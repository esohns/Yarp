#!/bin/sh
#//%%%FILE%%%////////////////////////////////////////////////////////////////////
#// File Name: bindings.sh
#//
#// History:
#//   Date   |Name | Description of modification
#// ---------|-----|-------------------------------------------------------------
#// 20/02/06 | soh | Creation.
#//%%%FILE%%%////////////////////////////////////////////////////////////////////

# C++ "glue code"
/usr/local/bin/XML2CppCode -e -f ./../rpg_common.xsd -i -o ./.. -s -u
/usr/local/bin/XML2CppCode -e -f ./../rpg_common_environment.xsd -i -o ./.. -s -u

# XML Parser
# generate "XMLSchema" namespace include file (rpg_common.xsd/rpg_common_environment.xsd)
/usr/bin/xsdcxx cxx-parser --char-type char --output-dir ./.. --xml-parser xerces --force-overwrite --generate-xml-schema --skel-file-suffix "" --hxx-suffix .h --show-anonymous --show-sloc ../rpg_XMLSchema_XML_types.xsd

# generate include/implementation (rpg_common.xsd)
/usr/bin/xsdcxx cxx-parser --type-map ./../rpg_common.map --char-type char --output-dir ./.. --namespace-map urn:rpg= --xml-parser xerces --force-overwrite --extern-xml-schema rpg_XMLSchema.h --skel-file-suffix _XML_types --hxx-suffix .h --cxx-suffix .cpp --show-anonymous --show-sloc ./../rpg_common.xsd

# generate include/implementation (rpg_common_environment.xsd)
/usr/bin/xsdcxx cxx-parser --type-map ./../rpg_common_environment.map --char-type char --output-dir ./.. --namespace-map urn:rpg= --xml-parser xerces --force-overwrite --extern-xml-schema rpg_XMLSchema.h --skel-file-suffix _XML_types --hxx-suffix .h --cxx-suffix .cpp --show-anonymous --show-sloc ./../rpg_common_environment.xsd

# generate "XMLSchema" namespace include file (tree)
/usr/bin/xsdcxx cxx-tree --char-type char --output-dir ./.. --generate-serialization --generate-insertion ACE_OutputCDR --generate-extraction ACE_InputCDR --generate-xml-schema --hxx-suffix .h --show-anonymous --show-sloc ../rpg_XMLSchema_XML_tree.xsd

# generate tree include/implementation (rpg_common.xsd)
/usr/bin/xsdcxx cxx-tree --generate-serialization --generate-ostream --generate-comparison --generate-insertion ACE_OutputCDR --generate-extraction ACE_InputCDR --type-regex '/(.+) RPG_(.+)_Type/RPG_\u$2_XMLTree_Type/' --char-type char --output-dir ./.. --namespace-map urn:rpg= --extern-xml-schema rpg_XMLSchema.h --hxx-suffix _XML_tree.h --cxx-suffix _XML_tree.cpp --show-anonymous --show-sloc ../rpg_common.xsd

# generate tree include/implementation (rpg_common_environment.xsd)
/usr/bin/xsdcxx cxx-tree --generate-serialization --generate-ostream --generate-comparison --generate-insertion ACE_OutputCDR --generate-extraction ACE_InputCDR --type-regex '/(.+) RPG_(.+)_Type/RPG_\u$2_XMLTree_Type/' --char-type char --output-dir ./.. --namespace-map urn:rpg= --extern-xml-schema rpg_XMLSchema.h --hxx-suffix _XML_tree.h --cxx-suffix _XML_tree.cpp --show-anonymous --show-sloc ../rpg_common_environment.xsd
