
extern zend_class_entry *ice_validation_validator_regex_ce;

ZEPHIR_INIT_CLASS(Ice_Validation_Validator_Regex);

PHP_METHOD(Ice_Validation_Validator_Regex, validate);

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_validation_validator_regex_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_ice_validation_validator_regex_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Ice\\Validation, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(ice_validation_validator_regex_method_entry) {
	PHP_ME(Ice_Validation_Validator_Regex, validate, arginfo_ice_validation_validator_regex_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
