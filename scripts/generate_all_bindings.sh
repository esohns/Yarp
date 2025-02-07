#!/bin/sh
# //%%%FILE%%%////////////////////////////////////////////////////////////////////
# // File Name: generate_all_bindings.sh
# //
# // History:
# //   Date   |Name | Description of modification
# // ---------|-----|-------------------------------------------------------------
# // 20/02/06 | soh | Creation.
# //%%%FILE%%%////////////////////////////////////////////////////////////////////

#DEFAULT_PROJECT_DIR="${HOME}/Projects/yarp"
DEFAULT_PROJECT_DIR=.
PROJECT_DIR=${DEFAULT_PROJECT_DIR}
## sanity check(s)
#[ ! -d ${PROJECT_DIR} ] && echo "ERROR: invalid project directory (was: \"${PROJECT_DIR}\"), aborting" && exit 1

## remember current dir...
#pushd . >/dev/null 2>&1

#cd ${PROJECT_DIR}
#[ $? -ne 0 ] && echo "ERROR: failed to switch to project directory (was: \"${PROJECT_DIR}\"), aborting" && exit 1

# ..........................................

echo "generating .so exports headers..."
${PROJECT_DIR}/chance/scripts/exports.sh
${PROJECT_DIR}/net/scripts/exports.sh
${PROJECT_DIR}/net/protocol/scripts/exports.sh
[ $? -ne 0 ] && echo "ERROR: failed generating .so exports headers, aborting" && exit 1
echo "generating .so exports headers...DONE"

# ..........................................

echo "generating XML data bindings..."
${PROJECT_DIR}/chance/dice/scripts/bindings.sh
${PROJECT_DIR}/character/scripts/bindings.sh
${PROJECT_DIR}/character/player/scripts/bindings.sh
${PROJECT_DIR}/character/monster/scripts/bindings.sh
${PROJECT_DIR}/combat/scripts/bindings.sh
${PROJECT_DIR}/common/scripts/bindings.sh
${PROJECT_DIR}/engine/scripts/bindings.sh
${PROJECT_DIR}/graphics/scripts/bindings.sh
${PROJECT_DIR}/item/scripts/bindings.sh
${PROJECT_DIR}/magic/scripts/bindings.sh
${PROJECT_DIR}/map/scripts/bindings.sh
${PROJECT_DIR}/sound/scripts/bindings.sh
${PROJECT_DIR}/client/scripts/bindings.sh
[ $? -ne 0 ] && echo "ERROR: failed generating XML data bindings, aborting" && exit 1
echo "generating XML data bindings...DONE"

# ..........................................

echo "generating lex/yacc parsers..."
${PROJECT_DIR}/map/scripts/scanner.sh
${PROJECT_DIR}/map/scripts/parser.sh
${PROJECT_DIR}/net/protocol/scripts/scanner.sh
${PROJECT_DIR}/net/protocol/scripts/parser.sh
[ $? -ne 0 ] && echo "ERROR: failed generating lex/yacc parsers, aborting" && exit 1
echo "generating lex/yacc parsers...DONE"

#popd >/dev/null 2>&1
