#!/bin/sh
#//%%%FILE%%%////////////////////////////////////////////////////////////////////
#// File Name: bindings.sh
#//
#// History:
#//   Date   |Name | Description of modification
#// ---------|-----|-------------------------------------------------------------
#// 20/02/06 | soh | Creation.
#//%%%FILE%%%////////////////////////////////////////////////////////////////////

# sanity check(s)
command -v perl >/dev/null 2>&1 || { echo "Perl is not installed. Aborting." >&2; exit 1; }
command -v XML2CppCode >/dev/null 2>&1 || { echo "XML2CppCode is not installed. Aborting." >&2; exit 1; }
command -v xsdcxx >/dev/null 2>&1 || { echo "xsdcxx is not installed. Aborting." >&2; exit 1; }

# generate exports file
perl /usr/lib/ace/bin/generate_export_file.pl -n RPG_Item > ./../rpg_item_exports.h

# C++ "glue code"
XML2CppCode -e -f ./../rpg_item.xsd -i -o ./.. -s -u

# generate "XMLSchema" namespace include file (rpg_item.xsd)
xsdcxx cxx-parser --char-type char --output-dir ./.. --xml-parser xerces --force-overwrite --generate-xml-schema --skel-file-suffix "" --hxx-suffix .h --show-anonymous --show-sloc ../rpg_XMLSchema_XML_types.xsd

# generate parser include/implementation (rpg_item.xsd)
xsdcxx cxx-parser --type-map ../rpg_item.map --char-type char --output-dir ./.. --namespace-map urn:rpg= --xml-parser xerces --force-overwrite --extern-xml-schema rpg_XMLSchema.h --skel-file-suffix _XML_types --hxx-suffix .h --cxx-suffix .cpp --show-anonymous --show-sloc --export-symbol "RPG_Item_Export" --hxx-prologue "#include \"rpg_item_exports.h\"" ../rpg_item.xsd

# generate "XMLSchema" namespace include file (tree)
xsdcxx cxx-tree --char-type char --output-dir ./.. --generate-serialization --generate-xml-schema --hxx-suffix .h --show-anonymous --show-sloc ../rpg_XMLSchema_XML_tree.xsd
#xsdcxx cxx-tree --char-type char --output-dir ./.. --generate-serialization --generate-insertion ACE_OutputCDR --generate-extraction ACE_InputCDR --generate-xml-schema --hxx-suffix .h --show-anonymous --show-sloc ../rpg_XMLSchema_XML_tree.xsd

# generate tree include/implementation (rpg_item.xsd)
xsdcxx cxx-tree --generate-serialization --generate-ostream --generate-comparison --type-regex '/(.+) RPG_(.+)_Type/RPG_\u$2_XMLTree_Type/' --root-element-none --char-type char --output-dir ./.. --namespace-map urn:rpg= --extern-xml-schema rpg_XMLSchema.h --hxx-suffix _XML_tree.h --cxx-suffix _XML_tree.cpp --show-anonymous --show-sloc --export-symbol "RPG_Item_Export" --hxx-prologue "#include \"rpg_item_exports.h\"" ../rpg_item.xsd
#xsdcxx cxx-tree --generate-serialization --generate-ostream --generate-comparison --generate-insertion ACE_OutputCDR --generate-extraction ACE_InputCDR --type-regex '/(.+) RPG_(.+)_Type/RPG_\u$2_XMLTree_Type/' --root-element-none --char-type char --output-dir ./.. --namespace-map urn:rpg= --extern-xml-schema rpg_XMLSchema.h --hxx-suffix _XML_tree.h --cxx-suffix _XML_tree.cpp --show-anonymous --show-sloc --export-symbol "RPG_Item_Export" --hxx-prologue "#include \"rpg_item_exports.h\"" ../rpg_item.xsd

