# Doxyfile 1.5.7.1-KDevelop

#---------------------------------------------------------------------------
# Project related configuration options
#---------------------------------------------------------------------------
DOXYFILE_ENCODING      = UTF-8
PROJECT_NAME           = ${CPACK_PACKAGE_NAME}
PROJECT_NUMBER         = ${VERSION}
OUTPUT_DIRECTORY       = api-doc
CREATE_SUBDIRS         = NO
OUTPUT_LANGUAGE        = English
BRIEF_MEMBER_DESC      = YES
REPEAT_BRIEF           = YES
ABBREVIATE_BRIEF       = "The $name class" \
                         "The $name widget" \
                         "The $name file" \
                         is \
                         provides \
                         specifies \
                         contains \
                         represents \
                         a \
                         an \
                         the
ALWAYS_DETAILED_SEC    = NO
INLINE_INHERITED_MEMB  = NO
FULL_PATH_NAMES        = NO
STRIP_FROM_PATH        = ${CMAKE_CURRENT_SOURCE_DIR}
STRIP_FROM_INC_PATH    =
SHORT_NAMES            = NO
JAVADOC_AUTOBRIEF      = NO
QT_AUTOBRIEF           = NO
MULTILINE_CPP_IS_BRIEF = NO
INHERIT_DOCS           = YES
SEPARATE_MEMBER_PAGES  = NO
TAB_SIZE               = 2
ALIASES                =
OPTIMIZE_OUTPUT_FOR_C  = NO
OPTIMIZE_OUTPUT_JAVA   = NO
OPTIMIZE_FOR_FORTRAN   = NO
OPTIMIZE_OUTPUT_VHDL   = NO
EXTENSION_MAPPING      =
BUILTIN_STL_SUPPORT    = YES
CPP_CLI_SUPPORT        = NO
SIP_SUPPORT            = NO
IDL_PROPERTY_SUPPORT   = YES
DISTRIBUTE_GROUP_DOC   = NO
SUBGROUPING            = YES
TYPEDEF_HIDES_STRUCT   = NO
SYMBOL_CACHE_SIZE      = 0
#---------------------------------------------------------------------------
# Build related configuration options
#---------------------------------------------------------------------------
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES
EXTRACT_LOCAL_CLASSES  = YES
EXTRACT_LOCAL_METHODS  = NO
EXTRACT_ANON_NSPACES   = YES
HIDE_UNDOC_MEMBERS     = NO
HIDE_UNDOC_CLASSES     = NO
HIDE_FRIEND_COMPOUNDS  = NO
HIDE_IN_BODY_DOCS      = NO
INTERNAL_DOCS          = NO
CASE_SENSE_NAMES       = NO
HIDE_SCOPE_NAMES       = NO
SHOW_INCLUDE_FILES     = YES
INLINE_INFO            = YES
SORT_MEMBER_DOCS       = NO
SORT_BRIEF_DOCS        = NO
SORT_GROUP_NAMES       = NO
SORT_BY_SCOPE_NAME     = NO
SORT_MEMBERS_CTORS_1ST = YES
GENERATE_TODOLIST      = YES
GENERATE_TESTLIST      = YES
GENERATE_BUGLIST       = YES
GENERATE_DEPRECATEDLIST= YES
ENABLED_SECTIONS       =
MAX_INITIALIZER_LINES  = 30
SHOW_USED_FILES        = YES
SHOW_DIRECTORIES       = NO
SHOW_FILES             = YES
SHOW_NAMESPACES        = NO
FILE_VERSION_FILTER    =
LAYOUT_FILE            =
#---------------------------------------------------------------------------
# configuration options related to warning and progress messages
#---------------------------------------------------------------------------
QUIET                  = NO
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = NO
WARN_IF_DOC_ERROR      = YES
WARN_NO_PARAMDOC       = NO
WARN_FORMAT            = "$file:$line: $text"
WARN_LOGFILE           =
#---------------------------------------------------------------------------
# configuration options related to the input files
#---------------------------------------------------------------------------
INPUT                  = ${CMAKE_CURRENT_SOURCE_DIR}
INPUT_ENCODING         = UTF-8
FILE_PATTERNS          = *.c \
                         *.cc \
                         *.cxx \
                         *.cpp \
                         *.c++ \
                         *.d \
                         *.java \
                         *.i \
                         *.ii \
                         *.ixx \
                         *.ipp \
                         *.i++ \
                         *.inl \
                         *.h \
                         *.hh \
                         *.hxx \
                         *.hpp \
                         *.h++ \
                         *.idl \
                         *.odl \
                         *.cs \
                         *.php \
                         *.php3 \
                         *.inc \
                         *.m \
                         *.mm \
                         *.dox \
                         *.py \
                         *.f90 \
                         *.f \
                         *.vhd \
                         *.vhdl \
                         *.C \
                         *.CC \
                         *.C++ \
                         *.II \
                         *.I++ \
                         *.H \
                         *.HH \
                         *.H++ \
                         *.CS \
                         *.PHP \
                         *.PHP3 \
                         *.M \
                         *.MM \
                         *.PY \
                         *.F90 \
                         *.F \
                         *.VHD \
                         *.VHDL \
                         *.C \
                         *.H \
                         *.tlh \
                         *.diff \
                         *.patch \
                         *.moc \
                         *.xpm \
                         *.dox
RECURSIVE              = YES
EXCLUDE                = ${CMAKE_CURRENT_BUILD_DIR}
EXCLUDE_SYMLINKS       = NO
EXCLUDE_PATTERNS       =
EXCLUDE_SYMBOLS        =
EXAMPLE_PATH           =
EXAMPLE_PATTERNS       = *
EXAMPLE_RECURSIVE      = NO
IMAGE_PATH             =
INPUT_FILTER           =
FILTER_PATTERNS        =
FILTER_SOURCE_FILES    = NO
#---------------------------------------------------------------------------
# configuration options related to source browsing
#---------------------------------------------------------------------------
SOURCE_BROWSER         = NO
INLINE_SOURCES         = NO
STRIP_CODE_COMMENTS    = YES
REFERENCED_BY_RELATION = NO
REFERENCES_RELATION    = NO
REFERENCES_LINK_SOURCE = YES
USE_HTAGS              = NO
VERBATIM_HEADERS       = NO
#---------------------------------------------------------------------------
# configuration options related to the alphabetical class index
#---------------------------------------------------------------------------
ALPHABETICAL_INDEX     = YES
COLS_IN_ALPHA_INDEX    = 5
IGNORE_PREFIX          = RPG_
#---------------------------------------------------------------------------
# configuration options related to the HTML output
#---------------------------------------------------------------------------
GENERATE_HTML          = YES
HTML_OUTPUT            = html
HTML_FILE_EXTENSION    = .html
HTML_HEADER            =
HTML_FOOTER            =
HTML_STYLESHEET        =
HTML_ALIGN_MEMBERS     = YES
HTML_DYNAMIC_SECTIONS  = YES
GENERATE_DOCSET        = NO
DOCSET_FEEDNAME        = "Doxygen generated docs"
DOCSET_BUNDLE_ID       = org.doxygen.Project
GENERATE_HTMLHELP      = YES
CHM_FILE               = ${CPACK_PACKAGE_NAME}.chm
HHC_LOCATION           =
GENERATE_CHI           = NO
CHM_INDEX_ENCODING     =
BINARY_TOC             = NO
TOC_EXPAND             = YES
GENERATE_QHP           = NO
QCH_FILE               =
QHP_NAMESPACE          =
QHP_VIRTUAL_FOLDER     = doc
#QHP_CUSTOM_FILTER_NAME =
QHP_CUST_FILTER_ATTRS  =
QHP_SECT_FILTER_ATTRS  =
QHG_LOCATION           =
GENERATE_ECLIPSEHELP   = NO
DISABLE_INDEX          = NO
ENUM_VALUES_PER_LINE   = 4
GENERATE_TREEVIEW      = YES
TREEVIEW_WIDTH         = 250
FORMULA_FONTSIZE       = 10
#---------------------------------------------------------------------------
# configuration options related to the LaTeX output
#---------------------------------------------------------------------------
GENERATE_LATEX         = NO
LATEX_OUTPUT           = latex
LATEX_CMD_NAME         = latex
MAKEINDEX_CMD_NAME     = makeindex
COMPACT_LATEX          = NO
PAPER_TYPE             = a4wide
EXTRA_PACKAGES         =
LATEX_HEADER           =
PDF_HYPERLINKS         = YES
USE_PDFLATEX           = YES
LATEX_BATCHMODE        = NO
LATEX_HIDE_INDICES     = NO
#---------------------------------------------------------------------------
# configuration options related to the RTF output
#---------------------------------------------------------------------------
GENERATE_RTF           = NO
RTF_OUTPUT             = rtf
COMPACT_RTF            = NO
RTF_HYPERLINKS         = NO
RTF_STYLESHEET_FILE    =
RTF_EXTENSIONS_FILE    =
#---------------------------------------------------------------------------
# configuration options related to the man page output
#---------------------------------------------------------------------------
GENERATE_MAN           = YES
MAN_OUTPUT             = man
MAN_EXTENSION          = .3
MAN_LINKS              = NO
#---------------------------------------------------------------------------
# configuration options related to the XML output
#---------------------------------------------------------------------------
GENERATE_XML           = NO
XML_OUTPUT             = xml
XML_SCHEMA             =
XML_DTD                =
XML_PROGRAMLISTING     = YES
#---------------------------------------------------------------------------
# configuration options for the AutoGen Definitions output
#---------------------------------------------------------------------------
GENERATE_AUTOGEN_DEF   = NO
#---------------------------------------------------------------------------
# configuration options related to the Perl module output
#---------------------------------------------------------------------------
GENERATE_PERLMOD       = NO
PERLMOD_LATEX          = NO
PERLMOD_PRETTY         = YES
PERLMOD_MAKEVAR_PREFIX =
#---------------------------------------------------------------------------
# Configuration options related to the preprocessor
#---------------------------------------------------------------------------
ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = NO
EXPAND_ONLY_PREDEF     = NO
SEARCH_INCLUDES        = NO
INCLUDE_PATH           =
INCLUDE_FILE_PATTERNS  =
PREDEFINED             =
EXPAND_AS_DEFINED      =
SKIP_FUNCTION_MACROS   = YES
#---------------------------------------------------------------------------
# Configuration::additions related to external references
#---------------------------------------------------------------------------
TAGFILES               =
GENERATE_TAGFILE       = ${CPACK_PACKAGE_NAME}.tag
ALLEXTERNALS           = NO
EXTERNAL_GROUPS        = YES
PERL_PATH              = /usr/bin/perl
#---------------------------------------------------------------------------
# Configuration options related to the dot tool
#---------------------------------------------------------------------------
CLASS_DIAGRAMS         = YES
MSCGEN_PATH            =
HIDE_UNDOC_RELATIONS   = YES
HAVE_DOT               = YES
DOT_FONTNAME           = FreeSans
DOT_FONTSIZE           = 10
DOT_FONTPATH           =
CLASS_GRAPH            = YES
COLLABORATION_GRAPH    = YES
GROUP_GRAPHS           = YES
UML_LOOK               = YES
TEMPLATE_RELATIONS     = NO
INCLUDE_GRAPH          = YES
INCLUDED_BY_GRAPH      = YES
CALL_GRAPH             = NO
CALLER_GRAPH           = NO
GRAPHICAL_HIERARCHY    = YES
DIRECTORY_GRAPH        = YES
DOT_IMAGE_FORMAT       = png
DOT_PATH               =
DOTFILE_DIRS           =
DOT_GRAPH_MAX_NODES    = 50
MAX_DOT_GRAPH_DEPTH    = 1000
DOT_TRANSPARENT        = NO
DOT_MULTI_TARGETS      = NO
GENERATE_LEGEND        = YES
DOT_CLEANUP            = YES
#---------------------------------------------------------------------------
# Configuration::additions related to the search engine
#---------------------------------------------------------------------------
SEARCHENGINE           = NO
