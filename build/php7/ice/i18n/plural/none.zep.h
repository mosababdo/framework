
extern zend_class_entry *ice_i18n_plural_none_ce;

ZEPHIR_INIT_CLASS(Ice_I18n_Plural_None);

PHP_METHOD(Ice_I18n_Plural_None, getCategory);

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_none_getcategory, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_i18n_plural_none_getcategory, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_i18n_plural_none_method_entry) {
	PHP_ME(Ice_I18n_Plural_None, getCategory, arginfo_ice_i18n_plural_none_getcategory, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
