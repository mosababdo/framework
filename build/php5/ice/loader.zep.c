
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/require.h"


/**
 * PSR-4 autoloader class.
 *
 * @package     Ice/Loader
 * @category    Library
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Loader) {

	ZEPHIR_REGISTER_CLASS(Ice, Loader, ice, loader, ice_loader_method_entry, 0);

	zend_declare_property_null(ice_loader_ce, SL("prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	ice_loader_ce->create_object = zephir_init_properties_Ice_Loader;
	return SUCCESS;

}

/**
 * Register loader with SPL autoloader stack.
 * 
 * @return void
 */
PHP_METHOD(Ice_Loader, register) {

	zval *_1;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 158, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a base directory for a namespace prefix.
 *
 * @param string prefix The namespace prefix
 * @param string baseDir A base directory for class files in the namespace
 * @param bool prepend If true, prepend the base directory to the stack instead of appending it; this causes it to
 * be searched first rather than last
 * @return Loader
 */
PHP_METHOD(Ice_Loader, addNamespace) {

	zval *_10$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_bool prepend;
	zval *prefix_param = NULL, *baseDir_param = NULL, *prepend_param = NULL, *_0, _1, *_2, *_3, _4, *_5, *_6, _7, *_8, *_9, *_11$$3 = NULL, *_13$$4, *_14$$4, *_15$$4 = NULL, *_16$$5, *_17$$5, *_18$$5 = NULL;
	zval *prefix = NULL, *baseDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &prefix_param, &baseDir_param, &prepend_param);

	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(baseDir, baseDir_param);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\\");
	zephir_get_strval(prefix, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "/", 0);
	zephir_fast_trim(_3, baseDir, &_4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _3, "/");
	zephir_get_strval(baseDir, _5);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_trim(_6, baseDir, &_7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, _6, "/");
	zephir_get_strval(baseDir, _8);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_9, prefix))) {
		ZEPHIR_INIT_VAR(_10$$3);
		zephir_create_array(_10$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "utf8_encode", &_12, 159, baseDir);
		zephir_check_call_status();
		zephir_array_fast_append(_10$$3, _11$$3);
		zephir_update_property_array(this_ptr, SL("prefixes"), prefix, _10$$3 TSRMLS_CC);
		RETURN_THIS();
	}
	if (prepend) {
		_13$$4 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_14$$4, _13$$4, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 55 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_15$$4, "utf8_encode", &_12, 159, baseDir);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(_14$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 83, _14$$4, _15$$4);
		ZEPHIR_UNREF(_14$$4);
		zephir_check_call_status();
	} else {
		_16$$5 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_17$$5, _16$$5, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 57 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_18$$5, "utf8_encode", &_12, 159, baseDir);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(_17$$5);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 160, _17$$5, _18$$5);
		ZEPHIR_UNREF(_17$$5);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Loads the class file for a given class name.
 *
 * @param string className The fully-qualified class name
 * @return mixed The mapped file name on success, or boolean false on failure
 */
PHP_METHOD(Ice_Loader, loadClass) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	zval *className_param = NULL, *prefix = NULL, *pos = NULL, *relativeClass = NULL, *mappedFile = NULL, _0, *_2$$3, _4$$6 = zval_used_for_init, _5$$6 = zval_used_for_init, _6$$6 = zval_used_for_init, *_7$$6 = NULL, _8$$6 = zval_used_for_init, _9$$6 = zval_used_for_init;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	ZEPHIR_CPY_WRT(prefix, className);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\\", 0);
	ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 161, prefix, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(pos)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "\\", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&mappedFile, this_ptr, "loadmappedfile", &_3, 0, _2$$3, className);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(mappedFile)) {
			RETURN_CCTOR(mappedFile);
		}
	} else {
		do {
			ZEPHIR_SINIT_NVAR(_4$$6);
			ZVAL_LONG(&_4$$6, 0);
			ZEPHIR_SINIT_NVAR(_5$$6);
			ZVAL_LONG(&_5$$6, (zephir_get_numberval(pos) + 1));
			ZEPHIR_INIT_NVAR(prefix);
			zephir_substr(prefix, className, 0 , zephir_get_intval(&_5$$6), 0);
			ZEPHIR_SINIT_NVAR(_6$$6);
			ZVAL_LONG(&_6$$6, (zephir_get_numberval(pos) + 1));
			ZEPHIR_INIT_NVAR(relativeClass);
			zephir_substr(relativeClass, className, zephir_get_intval(&_6$$6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&mappedFile, this_ptr, "loadmappedfile", &_3, 0, prefix, relativeClass);
			zephir_check_call_status();
			if (zephir_is_true(mappedFile)) {
				RETURN_CCTOR(mappedFile);
			}
			ZEPHIR_INIT_NVAR(_7$$6);
			ZEPHIR_SINIT_NVAR(_8$$6);
			ZVAL_STRING(&_8$$6, "\\", 0);
			zephir_fast_trim(_7$$6, prefix, &_8$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_CPY_WRT(prefix, _7$$6);
			ZEPHIR_SINIT_NVAR(_9$$6);
			ZVAL_STRING(&_9$$6, "\\", 0);
			ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_1, 161, prefix, &_9$$6);
			zephir_check_call_status();
		} while (!ZEPHIR_IS_FALSE_IDENTICAL(pos));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Load the mapped file for a namespace prefix and relative class.
 * 
 * @param string $prefix The namespace prefix
 * @param string $relative_class The relative class name
 * @return mixed Boolean false if no mapped file can be loaded, or the name of the mapped file that was loaded
 */
PHP_METHOD(Ice_Loader, loadMappedFile) {

	HashTable *_8;
	HashPosition _7;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *relativeClass_param = NULL, *baseDir = NULL, *file = NULL, *_0, *_1, _2, _3, *_4, *_5, *_6, **_9, *_10$$4 = NULL;
	zval *prefix = NULL, *relativeClass = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &relativeClass_param);

	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(relativeClass, relativeClass_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, prefix))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "\\", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_str_replace(&_1, &_2, &_3, relativeClass TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _1, ".php");
	zephir_get_strval(relativeClass, _4);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	zephir_array_fetch(&_6, _5, prefix, PH_NOISY | PH_READONLY, "ice/loader.zep", 130 TSRMLS_CC);
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "ice/loader.zep", 144);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(baseDir, _9);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VV(file, baseDir, relativeClass);
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "requirefile", &_11, 0, file);
		zephir_check_call_status();
		if (zephir_is_true(_10$$4)) {
			RETURN_CCTOR(file);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * If a file exists, require it from the file system.
 * 
 * @param string $file The file to require
 * @return bool True if the file exists, false if not
 */
PHP_METHOD(Ice_Loader, requireFile) {

	zval *file_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(file, file_param);


	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

zend_object_value zephir_init_properties_Ice_Loader(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("prefixes"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

