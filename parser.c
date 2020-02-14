#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

//Enumeration

typedef enum {
    NOTA_TOKEN,PRINT_TOKEN,GETWD_TOKEN,SETWD_TOKEN,SCAN_TOKEN,LOG_TOKEN,MAX_TOKEN,MIN_TOKEN,ROUND_TOKEN,SIGNIF_TOKEN,COR_TOKEN,EXP_TOKEN,
    C_TOKEN,SORT_TOKEN,REV_TOKEN,UNIQUE_TOKEN,TABLE_TOKEN,AS_TOKEN,IF_TOKEN,ELSE_TOKEN,WHILE_TOKEN,REPEAT_TOKEN,FOR_TOKEN,
    SWITCH_TOKEN,BREAK_TOKEN,NEXT_TOKEN,FUNCTION_TOKEN,BODY_TOKEN,INPUT_TOKEN,END_TOKEN,OF_TOKEN,TYPEOF_TOKEN,
    LIST_TOKEN,DATAFRAME_TOKEN,ATTR_TOKEN,CHARACTER_TOKEN,ATOMIC_TOKEN,
    VECTOR_TOKEN,AS_NUMERIC_TOKEN,AS_DOUBLE_TOKEN,AS_INTEGER_TOKEN,AS_CHARACTER_TOKEN,IS_LOGICAL_TOKEN,IS_INTEGER_TOKEN,
    IS_DOUBLE_TOKEN,IS_CHARACTER_TOKEN,IS_ATOMIC_TOKEN,IS_VECTOR_TOKEN,IS_NUMERIC_TOKEN,TRUE_TOKEN,FALSE_TOKEN,
    LENGTH_TOKEN,PI_TOKEN,LETTERS_TOKEN,LS_TOKEN,PAT_TOKEN,LS_STR_TOKEN,MAX_LEVEL_TOKEN,EPS_TOKEN,MONTH_NAME_TOKEN,MONTH_ABB_TOKEN,
    NULL_TOKEN,RM_TOKEN,HELP_TOKEN,MODE_TOKEN,CAT_TOKEN,SEP_TOKEN,QUOTE_TOKEN,HEADER_TOKEN,DEC_TOKEN,READ_CSV_TOKEN,READ_CSV2_TOKEN,
    READ_DELIM_TOKEN,READ_DELIM2_TOKEN,READ_TABLE_TOKEN,ROWNAMES_TOKEN,COLNAMES_TOKEN,FILE_TOKEN,SEQ_TOKEN,FROM_TOKEN,REP_TOKEN,
    SEQUENCE_TOKEN,TO_TOKEN,GL_TOKEN,LABEL_TOKEN,RNORM_TOKEN,DNORM_TOKEN,PNORM_TOKEN,QNORM_TOKEN,REXP_TOKEN,DEXP_TOKEN,
    PEXP_TOKEN,QEXP_TOKEN,RGAMMA_TOKEN,DGAMMA_TOKEN,PGAMMA_TOKEN,QGAMMA_TOKEN,RNBINOM_TOKEN,DNBINOM_TOKEN,PNBINOM_TOKEN,QNBINOM_TOKEN,
    RUNIF_TOKEN,DUNIF_TOKEN,PUNIF_TOKEN,QUNIF_TOKEN,RGEOM_TOKEN,DGEOM_TOKEN,PGEOM_TOKEN,QGEOM_TOKEN,RCAUCHY_TOKEN,DCAUCHY_TOKEN,
    PCAUCHY_TOKEN,QCAUCHY_TOKEN,RPOIS_TOKEN,DPOIS_TOKEN,PPOIS_TOKEN,QPOIS_TOKEN,RF_TOKEN,DF_TOKEN,PF_TOKEN,QF_TOKEN,RT_TOKEN,DT_TOKEN,
    PT_TOKEN,QT_TOKEN,RLOGIS_TOKEN,DLOGIS_TOKEN,PLOGIS_TOKEN,QLOGIS_TOKEN,SCALE_TOKEN,LOCATION_TOKEN,MEAN_TOKEN,RATE_TOKEN,FACTOR_TOKEN,
    LEVEL_TOKEN,LABELS_TOKEN,EXCLUDE_TOKEN,

    LOG2_TOKEN,LOG10_TOKEN,COS_TOKEN,SIN_TOKEN,TAN_TOKEN,ACOS_TOKEN,ASIN_TOKEN,ATAN_TOKEN,ABS_TOKEN,SQRT_TOKEN,RANGE_TOKEN,SUM_TOKEN,
    PROD_TOKEN,SD_TOKEN,VAR_TOKEN,IS_COMPLEX_TOKEN,AS_LOGICAL_TOKEN,IS_NA_TOKEN,IS_NAN_TOKEN,NAMES_TOKEN,RBIND_TOKEN,CBIND_TOKEN,
    MATRIX_TOKEN,DATA_TOKEN,NROW_TOKEN,NCOL_TOKEN,BYROW_TOKEN,DIMNAMES_TOKEN,T_TOKEN,DIM_TOKEN,ROWSUMS_TOKEN,COLSUMS_TOKEN,
    COLMEANS_TOKEN,ROWMEANS_TOKEN,APPLY_TOKEN,LEVELS_TOKEN,IS_FACTOR_TOKEN,AS_FACTOR_TOKEN,SUMMARY_TOKEN,TAPPLY_TOKEN,
    IS_DATA_FRAME_TOKEN,AS_DATA_FRAME_TOKEN,SUBSET_TOKEN,ATTACH_TOKEN,DETACH_TOKEN,FILE_CHOOSE_TOKEN,READ_TSV_TOKEN,WRITE_TABLE_TOKEN,
    WRITE_CSV_TOKEN,WRITE_CSV2_TOKEN,SAVERDS_TOKEN,READRDS_TOKEN,LOAD_TOKEN,SAVE_TOKEN,SAVE_IMAGE_TOKEN,NA_TOKEN,CLASS_TOKEN,


    PV_TOKEN,PARO_TOKEN,PARF_TOKEN,MINUS_TOKEN,PLS_TOKEN,MULT_TOKEN,DIV_TOKEN,NEG_TOKEN,
    TILD_TOKEN,DP_TOKEN,INTER_TOKEN,POWER_TOKEN,INF_TOKEN,SUP_TOKEN,EG_TOKEN,EQ_TOKEN,DIFF_TOKEN,INFEG_TOKEN,SUPEG_TOKEN,DET_TOKEN,
    ET_TOKEN,OU_TOKEN,DOU_TOKEN,AFFTOD_TOKEN,AFFTOG_TOKEN,VIR_TOKEN,DOLLAR_TOKEN,IN_TOKEN,MOD_TOKEN,DQ_TOKEN,SQ_TOKEN,
    ACCO_TOKEN,ACCF_TOKEN,BRO_TOKEN,BRF_TOKEN,SEPARATEUR_TOKEN,
    
    INTEGER_TOKEN,DOUBLE_TOKEN,LOGICAL_TOKEN,STRING_TOKEN,NEWLINE_TOKEN,
    
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEX_TOKEN, ELSEIF_TOKEN

}CODES_LEX;

//enumeration d'erreur 

typedef struct {
    char TOKEN_NAME[40];
    CODES_LEX CODE;
}TOKEN;

typedef struct {
    char TOKEN_TEXT[40];
    CODES_LEX CODE;
}TOKEN_TEXT;


typedef struct {
    CODES_LEX CODE;
    char NOM[101];
}TSym_Cour;

int DEBUTMOTCLE = 0;
int FINMOTCLE = 194;
//Analyseur Symantique: declaration
//////////////

typedef enum{TINTEGER, TDOUBLE, TLOGIQUE, TVECTOR, TMATRIX, TDATAFRAME, TFACTORS, TLIST, TSTRING, TCOMPLEX} TSYM;

typedef struct 
{
    char nom[40];
    TSYM IDF;
    int ADRESSE;
    char valeur[40];
}T_TAB_IDF;


T_TAB_IDF IDFS[200]; // table des identificateur
int OFFSET = -1;

TOKEN ALLTOKENS[300] = {
    {"print",PRINT_TOKEN},
    {"getwd",GETWD_TOKEN},
    {"setwd",SETWD_TOKEN},
    {"scan",SCAN_TOKEN},
    {"log",LOG_TOKEN},
    {"max",MAX_TOKEN},
    {"min",MIN_TOKEN},
    {"round",ROUND_TOKEN},
    {"signif",SIGNIF_TOKEN},
    {"cor",COR_TOKEN},
    {"exp",EXP_TOKEN},
    {"c",C_TOKEN},
    {"sort",SORT_TOKEN},
    {"rev",REV_TOKEN},
    {"unique",UNIQUE_TOKEN},
    {"table",TABLE_TOKEN},
    {"as",AS_TOKEN},
    {"if",IF_TOKEN},
    {"else",ELSE_TOKEN},
    {"elseif",ELSEIF_TOKEN},
    {"while",WHILE_TOKEN},
    {"repeat",REPEAT_TOKEN},
    {"for",FOR_TOKEN},
    {"switch",SWITCH_TOKEN},
    {"break",BREAK_TOKEN},
    {"next",NEXT_TOKEN},
    {"function",FUNCTION_TOKEN},
    {"body",BODY_TOKEN},
    {"input",INPUT_TOKEN},
    {"end",END_TOKEN},
    {"of",OF_TOKEN},
    {"typeof",TYPEOF_TOKEN},
    {"list",LIST_TOKEN},
    {"data.frame",DATAFRAME_TOKEN},
    {"attr",ATTR_TOKEN},
    {"character",CHARACTER_TOKEN},
    {"atomic",ATOMIC_TOKEN},
    {"vector",VECTOR_TOKEN},
    {"as.numeric",AS_NUMERIC_TOKEN},
    {"as.double",AS_DOUBLE_TOKEN},
    {"as.integer",AS_INTEGER_TOKEN},
    {"as.character",AS_CHARACTER_TOKEN},
    {"is.logical",IS_LOGICAL_TOKEN},
    {"is.integer",IS_INTEGER_TOKEN},
    {"is.double",IS_DOUBLE_TOKEN},
    {"is.character",IS_CHARACTER_TOKEN},
    {"is.atomic",IS_ATOMIC_TOKEN},
    {"is.vector",IS_VECTOR_TOKEN},
    {"is.numeric",IS_NUMERIC_TOKEN},
    {"FALSE",FALSE_TOKEN},
    {"TRUE",TRUE_TOKEN},
    {"F",FALSE_TOKEN},
    {"T",TRUE_TOKEN},
    {"length",LENGTH_TOKEN},
    {"pi",PI_TOKEN},
    {"letters",LETTERS_TOKEN},
    {"ls",LS_TOKEN},
    {"pat",PAT_TOKEN},
    {"ls.str",LS_STR_TOKEN},
    {"max.level",MAX_LEVEL_TOKEN},
    {"eps",EPS_TOKEN},
    {"month.name",MONTH_NAME_TOKEN},
    {"month.abb",MONTH_ABB_TOKEN},
    {"NULL",NULL_TOKEN},
    {"rm",RM_TOKEN},
    {"help",HELP_TOKEN},
    {"mode",MODE_TOKEN},
    {"cat",CAT_TOKEN},
    {"sep",SEP_TOKEN},
    {"quote",QUOTE_TOKEN},
    {"header",HEADER_TOKEN},
    {"dec",DEC_TOKEN},
    {"read.csv",READ_CSV_TOKEN},
    {"read.csv2",READ_CSV2_TOKEN},
    {"read.delim",READ_DELIM_TOKEN},
    {"read.delim2",READ_DELIM2_TOKEN},
    {"read.table",READ_TABLE_TOKEN},
    {"rownames",ROWNAMES_TOKEN},
    {"colnames",COLNAMES_TOKEN},
    {"file",FILE_TOKEN},
    {"seq",SEQ_TOKEN},
    {"from",FROM_TOKEN},
    {"rep",REP_TOKEN},
    {"sequence",SEQUENCE_TOKEN},
    {"to",TO_TOKEN},
    {"gl",GL_TOKEN},
    {"label",LABEL_TOKEN},
    {"rnorm",RNORM_TOKEN},
    {"dnorm",DNORM_TOKEN},
    {"pnorm",PNORM_TOKEN},
    {"qnorm",QNORM_TOKEN},
    {"rexp",REXP_TOKEN},
    {"dexp",DEXP_TOKEN},
    {"pexp",PEXP_TOKEN},
    {"qexp",QEXP_TOKEN},
    {"rgamma",RGAMMA_TOKEN},
    {"dgamma",DGAMMA_TOKEN},
    {"pgamma",PGAMMA_TOKEN},
    {"qgamma",QGAMMA_TOKEN},
    {"rnbinom",RNBINOM_TOKEN},
    {"dnbinom",DNBINOM_TOKEN},
    {"pnbinom",PNBINOM_TOKEN},
    {"qnbinom",QNBINOM_TOKEN},
    {"runif",RUNIF_TOKEN},
    {"dunif",DUNIF_TOKEN},
    {"punif",PUNIF_TOKEN},
    {"qunif",QUNIF_TOKEN},
    {"rgeom",RGEOM_TOKEN},
    {"dgeom",DGEOM_TOKEN},
    {"pgeom",PGEOM_TOKEN},
    {"qgeom",QGEOM_TOKEN},
    {"rcauchy",RCAUCHY_TOKEN},
    {"dcauchy",DCAUCHY_TOKEN},
    {"pcauchy",PCAUCHY_TOKEN},
    {"qcauchy",QCAUCHY_TOKEN},
    {"rpois",RPOIS_TOKEN},
    {"dpois",DPOIS_TOKEN},
    {"ppois",PPOIS_TOKEN},
    {"qpois",QPOIS_TOKEN},
    {"rf",RF_TOKEN},
    {"df",DF_TOKEN},
    {"pf",PF_TOKEN},
    {"qf",QF_TOKEN},
    {"rt",RT_TOKEN},
    {"dt",DT_TOKEN},
    {"pt",PT_TOKEN},
    {"qt",QT_TOKEN},
    {"rlogis",RLOGIS_TOKEN},
    {"dlogis",DLOGIS_TOKEN},
    {"plogis",PLOGIS_TOKEN},
    {"qlogis",QLOGIS_TOKEN},
    {"scale",SCALE_TOKEN},
    {"location",LOCATION_TOKEN},
    {"mean",MEAN_TOKEN},
    {"rate",RATE_TOKEN},
    {"factor",FACTOR_TOKEN},
    {"level",LEVEL_TOKEN},
    {"labels",LABELS_TOKEN},
    {"exclude",EXCLUDE_TOKEN},
    {"log2",LOG2_TOKEN},
    {"log10",LOG10_TOKEN},
    {"cos",COS_TOKEN},
    {"sin",SIN_TOKEN},
    {"tan",TAN_TOKEN},
    {"acos",ACOS_TOKEN},
    {"asin",ASIN_TOKEN},
    {"atan",ATAN_TOKEN},
    {"abs",ABS_TOKEN},
    {"sqrt",SQRT_TOKEN},
    {"range",RANGE_TOKEN},
    {"sum",SUM_TOKEN},
    {"prod",PROD_TOKEN},
    {"sd",SD_TOKEN},
    {"var",VAR_TOKEN},
    {"is.complex",IS_COMPLEX_TOKEN},
    {"as.logical",AS_LOGICAL_TOKEN},
    {"is.na",IS_NA_TOKEN},
    {"is.nan",IS_NAN_TOKEN},
    {"names",NAMES_TOKEN},
    {"rbind",RBIND_TOKEN},
    {"cbind",CBIND_TOKEN},
    {"matrix",MATRIX_TOKEN},
    {"data",DATA_TOKEN},
    {"nrow",NROW_TOKEN},
    {"ncol",NCOL_TOKEN},
    {"byrow",BYROW_TOKEN},
    {"dimnames",DIMNAMES_TOKEN},
    {"t",T_TOKEN},
    {"dim",DIM_TOKEN},
    {"rowSums",ROWSUMS_TOKEN},
    {"colSums",COLSUMS_TOKEN},
    {"colMeans",COLMEANS_TOKEN},
    {"rowMeans",ROWMEANS_TOKEN},
    {"apply",APPLY_TOKEN},
    {"levels",LEVELS_TOKEN},
    {"is.factor",IS_FACTOR_TOKEN},
    {"as.factor",AS_FACTOR_TOKEN},
    {"summary",SUMMARY_TOKEN},
    {"tapply",TAPPLY_TOKEN},
    {"is.data.frame",IS_DATA_FRAME_TOKEN},
    {"as.data.frame",AS_DATA_FRAME_TOKEN},
    {"subset",SUBSET_TOKEN},
    {"attach",ATTACH_TOKEN},
    {"detach",DETACH_TOKEN},
    {"file.choose",FILE_CHOOSE_TOKEN},
    {"read.tsv",READ_TSV_TOKEN},
    {"write.table",WRITE_TABLE_TOKEN},
    {"write.csv",WRITE_CSV_TOKEN},
    {"write.csv2",WRITE_CSV2_TOKEN},
    {"saveRDS",SAVERDS_TOKEN},
    {"readRDS",READRDS_TOKEN},
    {"load",LOAD_TOKEN},
    {"save",SAVE_TOKEN},
    {"save.image",SAVE_IMAGE_TOKEN},
    {"NA",NA_TOKEN},
    {"class",CLASS_TOKEN},
    //fin utilisation de ce tableau
    {";",PV_TOKEN},
    {"(",PARO_TOKEN},
    {")",PARF_TOKEN},
    {"-",MINUS_TOKEN},
    {"+",PLS_TOKEN},
    {"*",MULT_TOKEN},
    {"/",DIV_TOKEN},
    {"!",NEG_TOKEN},
    {"~",TILD_TOKEN},
    {":",DP_TOKEN},
    {"?",INTER_TOKEN},
    {"^",POWER_TOKEN},
    {"<",INF_TOKEN},
    {">",SUP_TOKEN},
    {"=",EG_TOKEN},
    {"==",EQ_TOKEN},
    {"!=",DIFF_TOKEN},
    {"<=",INFEG_TOKEN},
    {">=",SUPEG_TOKEN},
    {"&&",DET_TOKEN},
    {"&",ET_TOKEN},
    {"|",OU_TOKEN},
    {"||",DOU_TOKEN},
    {"->",AFFTOD_TOKEN},
    {"<-",AFFTOG_TOKEN},
    {",",VIR_TOKEN},
    {"$",DOLLAR_TOKEN},
    {"%in%",IN_TOKEN},
    {"%%",MOD_TOKEN},
    {"\"",DQ_TOKEN},
    {"'",SQ_TOKEN},
    {"{",ACCO_TOKEN},
    {"}",ACCF_TOKEN},
    {"[",BRO_TOKEN},
    {"]",BRF_TOKEN},
    {"#",COM_TOKEN}
};

int NUMBEROFTOKENS = 240;

TOKEN_TEXT ALLTOKENS_TEXT[300] = {
    {"PRINT_TOKEN",PRINT_TOKEN},
    {"GETWD_TOKEN",GETWD_TOKEN},
    {"SETWD_TOKEN",SETWD_TOKEN},
    {"SCAN_TOKEN",SCAN_TOKEN},
    {"LOG_TOKEN",LOG_TOKEN},
    {"MAX_TOKEN",MAX_TOKEN},
    {"MIN_TOKEN",MIN_TOKEN},
    {"ROUND_TOKEN",ROUND_TOKEN},
    {"SIGNIF_TOKEN",SIGNIF_TOKEN},
    {"COR_TOKEN",COR_TOKEN},
    {"EXP_TOKEN",EXP_TOKEN},
    {"C_TOKEN",C_TOKEN},
    {"SORT_TOKEN",SORT_TOKEN},
    {"REV_TOKEN",REV_TOKEN},
    {"UNIQUE_TOKEN",UNIQUE_TOKEN},
    {"TABLE_TOKEN",TABLE_TOKEN},
    {"AS_TOKEN",AS_TOKEN},
    {"IF_TOKEN",IF_TOKEN},
    {"ELSE_TOKEN",ELSE_TOKEN},
    {"ELSEIF_TOKEN",ELSEIF_TOKEN},
    {"WHILE_TOKEN",WHILE_TOKEN},
    {"REPEAT_TOKEN",REPEAT_TOKEN},
    {"FOR_TOKEN",FOR_TOKEN},
    {"SWITCH_TOKEN",SWITCH_TOKEN},
    {"BREAK_TOKEN",BREAK_TOKEN},
    {"NEXT_TOKEN",NEXT_TOKEN},
    {"FUNCTION_TOKEN",FUNCTION_TOKEN},
    {"BODY_TOKEN",BODY_TOKEN},
    {"INPUT_TOKEN",INPUT_TOKEN},
    {"END_TOKEN",END_TOKEN},
    {"OF_TOKEN",OF_TOKEN},
    {"TYPEOF_TOKEN",TYPEOF_TOKEN},
    {"LIST_TOKEN",LIST_TOKEN},
    {"DATAFRAME_TOKEN",DATAFRAME_TOKEN},
    {"ATTR_TOKEN",ATTR_TOKEN},
    {"CHARACTER_TOKEN",CHARACTER_TOKEN},
    {"ATOMIC_TOKEN",ATOMIC_TOKEN},
    {"VECTOR_TOKEN",VECTOR_TOKEN},
    {"AS_NUMERIC_TOKEN",AS_NUMERIC_TOKEN},
    {"AS_DOUBLE_TOKEN",AS_DOUBLE_TOKEN},
    {"AS_INTEGER_TOKEN",AS_INTEGER_TOKEN},
    {"AS_CHARACTER_TOKEN",AS_CHARACTER_TOKEN},
    {"IS_LOGICAL_TOKEN",IS_LOGICAL_TOKEN},
    {"IS_INTEGER_TOKEN",IS_INTEGER_TOKEN},
    {"IS_DOUBLE_TOKEN",IS_DOUBLE_TOKEN},
    {"IS_CHARACTER_TOKEN",IS_CHARACTER_TOKEN},
    {"IS_ATOMIC_TOKEN",IS_ATOMIC_TOKEN},
    {"IS_VECTOR_TOKEN",IS_VECTOR_TOKEN},
    {"IS_NUMERIC_TOKEN",IS_NUMERIC_TOKEN},
    {"TRUE_TOKEN",TRUE_TOKEN},
    {"FALSE_TOKEN",FALSE_TOKEN},
    {"LENGTH_TOKEN",LENGTH_TOKEN},
    {"PI_TOKEN",PI_TOKEN},
    {"LETTERS_TOKEN",LETTERS_TOKEN},
    {"LS_TOKEN",LS_TOKEN},
    {"PAT_TOKEN",PAT_TOKEN},
    {"LS_STR_TOKEN",LS_STR_TOKEN},
    {"MAX_LEVEL_TOKEN",MAX_LEVEL_TOKEN},
    {"EPS_TOKEN",EPS_TOKEN},
    {"MONTH_NAME_TOKEN",MONTH_NAME_TOKEN},
    {"MONTH_ABB_TOKEN",MONTH_ABB_TOKEN},
    {"NULL_TOKEN",NULL_TOKEN},
    {"RM_TOKEN",RM_TOKEN},
    {"HELP_TOKEN",HELP_TOKEN},
    {"MODE_TOKEN",MODE_TOKEN},
    {"CAT_TOKEN",CAT_TOKEN},
    {"SEP_TOKEN",SEP_TOKEN},
    {"QUOTE_TOKEN",QUOTE_TOKEN},
    {"HEADER_TOKEN",HEADER_TOKEN},
    {"DEC_TOKEN",DEC_TOKEN},
    {"READ_CSV_TOKEN",READ_CSV_TOKEN},
    {"READ_CSV2_TOKEN",READ_CSV2_TOKEN},
    {"READ_DELIM_TOKEN",READ_DELIM_TOKEN},
    {"READ_DELIM2_TOKEN",READ_DELIM2_TOKEN},
    {"READ_TABLE_TOKEN",READ_TABLE_TOKEN},
    {"ROWNAMES_TOKEN",ROWNAMES_TOKEN},
    {"COLNAMES_TOKEN",COLNAMES_TOKEN},
    {"FILE_TOKEN",FILE_TOKEN},
    {"SEQ_TOKEN",SEQ_TOKEN},
    {"FROM_TOKEN",FROM_TOKEN},
    {"REP_TOKEN",REP_TOKEN},
    {"SEQUENCE_TOKEN",SEQUENCE_TOKEN},
    {"TO_TOKEN",TO_TOKEN},
    {"GL_TOKEN",GL_TOKEN},
    {"LABEL_TOKEN",LABEL_TOKEN},
    {"RNORM_TOKEN",RNORM_TOKEN},
    {"DNORM_TOKEN",DNORM_TOKEN},
    {"PNORM_TOKEN",PNORM_TOKEN},
    {"QNORM_TOKEN",QNORM_TOKEN},
    {"REXP_TOKEN",REXP_TOKEN},
    {"DEXP_TOKEN",DEXP_TOKEN},
    {"PEXP_TOKEN",PEXP_TOKEN},
    {"QEXP_TOKEN",QEXP_TOKEN},
    {"RGAMMA_TOKEN",RGAMMA_TOKEN},
    {"DGAMMA_TOKEN",DGAMMA_TOKEN},
    {"PGAMMA_TOKEN",PGAMMA_TOKEN},
    {"QGAMMA_TOKEN",QGAMMA_TOKEN},
    {"RNBINOM_TOKEN",RNBINOM_TOKEN},
    {"DNBINOM_TOKEN",DNBINOM_TOKEN},
    {"PNBINOM_TOKEN",PNBINOM_TOKEN},
    {"QNBINOM_TOKEN",QNBINOM_TOKEN},
    {"RUNIF_TOKEN",RUNIF_TOKEN},
    {"DUNIF_TOKEN",DUNIF_TOKEN},
    {"PUNIF_TOKEN",PUNIF_TOKEN},
    {"QUNIF_TOKEN",QUNIF_TOKEN},
    {"RGEOM_TOKEN",RGEOM_TOKEN},
    {"DGEOM_TOKEN",DGEOM_TOKEN},
    {"PGEOM_TOKEN",PGEOM_TOKEN},
    {"QGEOM_TOKEN",QGEOM_TOKEN},
    {"RCAUCHY_TOKEN",RCAUCHY_TOKEN},
    {"DCAUCHY_TOKEN",DCAUCHY_TOKEN},
    {"PCAUCHY_TOKEN",PCAUCHY_TOKEN},
    {"QCAUCHY_TOKEN",QCAUCHY_TOKEN},
    {"RPOIS_TOKEN",RPOIS_TOKEN},
    {"DPOIS_TOKEN",DPOIS_TOKEN},
    {"PPOIS_TOKEN",PPOIS_TOKEN},
    {"QPOIS_TOKEN",QPOIS_TOKEN},
    {"RF_TOKEN",RF_TOKEN},
    {"DF_TOKEN",DF_TOKEN},
    {"PF_TOKEN",PF_TOKEN},
    {"QF_TOKEN",QF_TOKEN},
    {"RT_TOKEN",RT_TOKEN},
    {"DT_TOKEN",DT_TOKEN},
    {"PT_TOKEN",PT_TOKEN},
    {"QT_TOKEN",QT_TOKEN},
    {"RLOGIS_TOKEN",RLOGIS_TOKEN},
    {"DLOGIS_TOKEN",DLOGIS_TOKEN},
    {"PLOGIS_TOKEN",PLOGIS_TOKEN},
    {"QLOGIS_TOKEN",QLOGIS_TOKEN},
    {"SCALE_TOKEN",SCALE_TOKEN},
    {"LOCATION_TOKEN",LOCATION_TOKEN},
    {"MEAN_TOKEN",MEAN_TOKEN},
    {"RATE_TOKEN",RATE_TOKEN},
    {"FACTOR_TOKEN",FACTOR_TOKEN},
    {"LEVEL_TOKEN",LEVEL_TOKEN},
    {"LABELS_TOKEN",LABELS_TOKEN},
    {"EXCLUDE_TOKEN",EXCLUDE_TOKEN},
    {"LOG2_TOKEN",LOG2_TOKEN},
    {"LOG10_TOKEN",LOG10_TOKEN},
    {"COS_TOKEN",COS_TOKEN},
    {"SIN_TOKEN",SIN_TOKEN},
    {"TAN_TOKEN",TAN_TOKEN},
    {"ACOS_TOKEN",ACOS_TOKEN},
    {"ASIN_TOKEN",ASIN_TOKEN},
    {"ATAN_TOKEN",ATAN_TOKEN},
    {"ABS_TOKEN",ABS_TOKEN},
    {"SQRT_TOKEN",SQRT_TOKEN},
    {"RANGE_TOKEN",RANGE_TOKEN},
    {"SUM_TOKEN",SUM_TOKEN},
    {"PROD_TOKEN",PROD_TOKEN},
    {"SD_TOKEN",SD_TOKEN},
    {"VAR_TOKEN",VAR_TOKEN},
    {"IS_COMPLEX_TOKEN",IS_COMPLEX_TOKEN},
    {"AS_LOGICAL_TOKEN",AS_LOGICAL_TOKEN},
    {"IS_NA_TOKEN",IS_NA_TOKEN},
    {"IS_NAN_TOKEN",IS_NAN_TOKEN},
    {"NAMES_TOKEN",NAMES_TOKEN},
    {"RBIND_TOKEN",RBIND_TOKEN},
    {"CBIND_TOKEN",CBIND_TOKEN},
    {"MATRIX_TOKEN",MATRIX_TOKEN},
    {"DATA_TOKEN",DATA_TOKEN},
    {"NROW_TOKEN",NROW_TOKEN},
    {"NCOL_TOKEN",NCOL_TOKEN},
    {"BYROW_TOKEN",BYROW_TOKEN},
    {"DIMNAMES_TOKEN",DIMNAMES_TOKEN},
    {"T_TOKEN",T_TOKEN},
    {"DIM_TOKEN",DIM_TOKEN},
    {"ROWSUMS_TOKEN",ROWSUMS_TOKEN},
    {"COLSUMS_TOKEN",COLSUMS_TOKEN},
    {"COLMEANS_TOKEN",COLMEANS_TOKEN},
    {"ROWMEANS_TOKEN",ROWMEANS_TOKEN},
    {"APPLY_TOKEN",APPLY_TOKEN},
    {"LEVELS_TOKEN",LEVELS_TOKEN},
    {"IS_FACTOR_TOKEN",IS_FACTOR_TOKEN},
    {"AS_FACTOR_TOKEN",AS_FACTOR_TOKEN},
    {"SUMMARY_TOKEN",SUMMARY_TOKEN},
    {"TAPPLY_TOKEN",TAPPLY_TOKEN},
    {"IS_DATA_FRAME_TOKEN",IS_DATA_FRAME_TOKEN},
    {"AS_DATA_FRAME_TOKEN",AS_DATA_FRAME_TOKEN},
    {"SUBSET_TOKEN",SUBSET_TOKEN},
    {"ATTACH_TOKEN",ATTACH_TOKEN},
    {"DETACH_TOKEN",DETACH_TOKEN},
    {"FILE_CHOOSE_TOKEN",FILE_CHOOSE_TOKEN},
    {"READ_TSV_TOKEN",READ_TSV_TOKEN},
    {"WRITE_TABLE_TOKEN",WRITE_TABLE_TOKEN},
    {"WRITE_CSV_TOKEN",WRITE_CSV_TOKEN},
    {"WRITE_CSV2_TOKEN",WRITE_CSV2_TOKEN},
    {"SAVERDS_TOKEN",SAVERDS_TOKEN},
    {"READRDS_TOKEN",READRDS_TOKEN},
    {"LOAD_TOKEN",LOAD_TOKEN},
    {"SAVE_TOKEN",SAVE_TOKEN},
    {"SAVE_IMAGE_TOKEN",SAVE_IMAGE_TOKEN},
    {"NA_TOKEN",NA_TOKEN},
    {"CLASS_TOKEN",CLASS_TOKEN},
    {"PV_TOKEN",PV_TOKEN},
    {"PARO_TOKEN",PARO_TOKEN},
    {"PARF_TOKEN",PARF_TOKEN},
    {"MINUS_TOKEN",MINUS_TOKEN},
    {"PLS_TOKEN",PLS_TOKEN},
    {"MULT_TOKEN",MULT_TOKEN},
    {"DIV_TOKEN",DIV_TOKEN},
    {"NEG_TOKEN",NEG_TOKEN},
    {"TILD_TOKEN",TILD_TOKEN},
    {"DP_TOKEN",DP_TOKEN},
    {"INTER_TOKEN",INTER_TOKEN},
    {"POWER_TOKEN",POWER_TOKEN},
    {"INF_TOKEN",INF_TOKEN},
    {"SUP_TOKEN",SUP_TOKEN},
    {"EG_TOKEN",EG_TOKEN},
    {"EQ_TOKEN",EQ_TOKEN},
    {"DIFF_TOKEN",DIFF_TOKEN},
    {"INFEG_TOKEN",INFEG_TOKEN},
    {"SUPEG_TOKEN",SUPEG_TOKEN},
    {"DET_TOKEN",DET_TOKEN},
    {"ET_TOKEN",ET_TOKEN},
    {"OU_TOKEN",OU_TOKEN},
    {"DOU_TOKEN",DOU_TOKEN},
    {"AFFTOD_TOKEN",AFFTOD_TOKEN},
    {"AFFTOG_TOKEN",AFFTOG_TOKEN},
    {"VIR_TOKEN",VIR_TOKEN},
    {"DOLLAR_TOKEN",DOLLAR_TOKEN},
    {"IN_TOKEN",IN_TOKEN},
    {"MOD_TOKEN",MOD_TOKEN},
    {"DQ_TOKEN",DQ_TOKEN},
    {"SQ_TOKEN",SQ_TOKEN},
    {"ACCO_TOKEN",ACCO_TOKEN},
    {"ACCF_TOKEN",ACCF_TOKEN},
    {"BRO_TOKEN",BRO_TOKEN},
    {"BRF_TOKEN",BRF_TOKEN},
    {"SEPARATEUR_TOKEN",SEPARATEUR_TOKEN},
    {"INTEGER_TOKEN",INTEGER_TOKEN},
    {"DOUBLE_TOKEN",DOUBLE_TOKEN},
    {"LOGICAL_TOKEN",LOGICAL_TOKEN},
    {"STRING_TOKEN" ,STRING_TOKEN},
    {"NEWLINE_TOKEN" ,NEWLINE_TOKEN},
    {"COM_TOKEN",COM_TOKEN},
    {"ID_TOKEN",ID_TOKEN},
    {"FIN_TOKEN",FIN_TOKEN},
    {"ERREUR_TOKEN",ERREUR_TOKEN},
    {"COMPLEX_TOKEN",COMPLEX_TOKEN}
};

typedef enum {
    PARO_ERR,PARF_ERR,ID_STRING_ERR,STRING_ERR,ID_ERR,LEVELS_ERR,
    ASSIGN_ERR,C_ERR,TRUEFALSE_ERR,NUMERIC_ERR,VECTOR2_ERR,LS_ERR,
    SUBSET_DATAFRAME_ERR,VIR_ERR,LOG_OP_ERR,BASIC_TYPE_ERR,
    RM_ERR,NAMES_ERR,A_ERR,RENAME_ERR,EXP_ERR,EG_ERR,NLS_ERR,NLSNA_ERR,
    NL_ERR,BRF_ERR,DOUBLE_ERR,DP_ERR,DC_ERR,IS_NA_ERR,ID_NEG_IS_NA_ERR,
    DOUBLE_VIR_C_ERR,DOUBLE_C_TOKEN,BASIC_ID_ERR,AFFTOG_ERR,
    DATA_ERR,NCOL_ERR,BYROW_ERR,DIMNAMES_ERR,LIST_ERR,T_ERR
    ,VVARBASIC_ERR,PARAM_ERR, EXISID_ERR, IF_ERR, ELSE_ERR ,FOR_ERR, WHILE_ERR,REPEAT_ERR,
    EQ_ERR, ACCO_ERR, ACCF_ERR, COND_ERR, BREAK_ERR, INST_ERR, ELSEIF_ERR, FUNCTION_ERR
}Erreurs;

int NOMBRE_ERREUR = 200;

typedef struct {
    Erreurs CODE_ERR;
    char MES[100];
}Erreur;

Erreur MES_ERR[200] = {
    {PARO_ERR , "Parenthese Ouvrante Erreur"},
    {PARF_ERR , "Parenthese Fermante Erreur"},
    {ID_STRING_ERR, "ID ou String Erreur"},
    {STRING_ERR, "String Erreur"},
    {ID_ERR, "ID Erreur"},
    {LEVELS_ERR, "Levels Erreur"},
    {ASSIGN_ERR, "Assigning Erreur ( <- or = )"},
    {C_ERR, "Erreur dans C"},
    {TRUEFALSE_ERR, "True False Erreur"},
    {NUMERIC_ERR, "Double or integer Erreur"},
    {VECTOR2_ERR, "Contenu du Vecteur Erreur"},
    {LS_ERR, "List Erreur"},
    {SUBSET_DATAFRAME_ERR, "Subset Dataframe Erreur"},
    {VIR_ERR, "Virgule Erreur"},
    {LOG_OP_ERR, "LOGIC OPERATION ERREUR"},
    {BASIC_TYPE_ERR, "Basic Type Erreur"},
    {RM_ERR, "Remove Erreur"},
    {NAMES_ERR, "Names Erreur"},
    {A_ERR, "Affectation Erreur"},
    {RENAME_ERR, "Rename Erreur"},
    {EXP_ERR, "Expression Erreur"},
    {EG_ERR, "Symbole = Manquant"},
    {NLS_ERR, "NUMERIC LOgical or String Manquant"},
    {NLSNA_ERR, "Numeric Logical String or NA Manquant"},
    {NL_ERR, "Numeric or Logical Manquant"},
    {BRF_ERR ,"Braquette Fermante Manquante"},
    {DOUBLE_ERR, "Double Manquant"},
    {DP_ERR, "Double Point Manquant"},
    {DC_ERR, "Double Or C or (Double:Double) Vecteur Manquant"},
    {IS_NA_ERR, "is.na Manquante"},
    {ID_NEG_IS_NA_ERR, "Variable ou ! ou is.na Maquante"},
    {DOUBLE_VIR_C_ERR, "Double ou Virgule ou C() Manquant"},
    {DOUBLE_C_TOKEN, "Double or C Manquant"},
    {BASIC_ID_ERR, "Basic Type ou ID Manquant"},
    {AFFTOG_ERR ,"Affectation A gauche Erreur"},    
    {DATA_ERR, "Data Erreur"},
    {NCOL_ERR, "Ncolumn Erreur"},
    {BYROW_ERR, "By row Erreur"},
    {DIMNAMES_ERR ,"dim names Erreur"},
    {LIST_ERR ,"List Erreur"},
    {T_ERR, "Symbole T erreur"},
    {VVARBASIC_ERR,"Vecteur Var BasicType Manquant"},
    {PARAM_ERR, "Faute Dans les Parametres"},
    {EXISID_ERR, "Le ID est deja declarer"},
    {IF_ERR, "Erreur dans la syntaxe IF"},
    {ELSE_ERR,"Erreur dans la syntaxe ELSE"},
    {FOR_ERR, "Erreur dans la syntae FOR"},
    {WHILE_ERR, "Erreur dans la syntaxe WHILE"},
    {REPEAT_ERR, "Erreur dans la syntaxe REPEAT"},
    {EQ_ERR, "== Manquant"},
    {ACCO_ERR, "{ Manquant"},
    {ACCF_ERR, "} Manquant"},
    {COND_ERR, "Erreur dans la condition"},
    {BREAK_ERR, "Break Erreur"},
    {INST_ERR, "Trop d'instructions dans un ligne"},
    {ELSEIF_ERR, "Erreur dans ELSEIF syntaxe"},
    {FUNCTION_ERR, "Erreur dans la declaration de la focntion"}
};



// Variable Globale
int MAX_ID_NAME_LENGTH = 100;
char Car_Cour;
FILE *file;
TSym_Cour SYM_COUR;
int Ligne_Courante = 1;
int NbrId= 0;
int Colonne_Courante = 0;
char NOM[101];
int Length_NOM = 0;
int switcher = 0;
CODES_LEX CODE_TEMP,CODE_VER;


//Prototypes
void Vider_NOM();
void Ouvrir_Fichier(const char path[]);
void Lire_Car();
bool Separateur();
void Sym_Suiv();
void AfficherToken(TSym_Cour SYM);
CODES_LEX code_mot_cle(char nom[]);
void lire_mot();
void lire_special();
void lire_commentaire();
void lire_nombre();
int isalpha();
int isdigit();
void lire_chaine();
void lire_separateur();
int chercherTabIdent(char * chaineId);
int ajouterTabIden(char* chaineId, TSYM ct);
void Erreur_aff( Erreurs e);





int chercherTabIdent(char *chaineId){
    int i;
    for(i=0;i<NbrId;i++){
        if(strcmp(chaineId,IDFS[i].nom)) return i;
    }
    return -1;
}

int ajouterTabIden(char *chaineId, TSYM ct){
    int adresse;
    if(chercherTabIdent(chaineId)==-1){
        IDFS[NbrId].IDF = ct;
        adresse = ++OFFSET;
        IDFS[NbrId].ADRESSE = adresse;
        strcpy(IDFS[NbrId].nom,chaineId);
        NbrId++;
        return adresse;
    }
    else Erreur_aff(EXISID_ERR);
}
void Vider_NOM() {
    Length_NOM = 0;
    memset(NOM,'\0',101);
    memset(SYM_COUR.NOM,'\0',101);
}

void Ouvrir_Fichier(const char path[]){
    file = fopen(path,"r");
    if(file == NULL) {
      /*ERR_Cour.CODE_ERR = ERR_FICH_INEX;
      Erreur_aff(ERR_Cour.CODE_ERR);*/
      perror("Error in opening file");
      return;
    }
}

void Lire_Car(){
    Car_Cour = fgetc(file);
    Colonne_Courante++;
}

bool Separateur() {
    char separateur[] = {' ','\t','\n','\r'};
    for (int i = 0; i < strlen(separateur) ; i++) {
        if(separateur[i] == Car_Cour) {
            return true;
        }
    }
    return false;    
}

void lire_separateur() {
    if(Car_Cour == '\n'){
        SYM_COUR.CODE = NEWLINE_TOKEN;
        Ligne_Courante++;
        Colonne_Courante = 0 ;
    }  else {
        SYM_COUR.CODE = SEPARATEUR_TOKEN;
    }
    SYM_COUR.NOM[0] = Car_Cour; 
    Lire_Car();
}

void Sym_Suiv(){
        if(Car_Cour == '#'){ lire_commentaire(); }
        else if(Separateur()){ lire_separateur(); }
        else if( isalpha(Car_Cour) || Car_Cour == '.'){ lire_mot(); }
        else if( isdigit(Car_Cour) ){ lire_nombre(); }
        else if(Car_Cour ==  '\"' || Car_Cour == 39){ lire_chaine(); }
        else { lire_special(); }
        Vider_NOM();
}

void AfficherToken(TSym_Cour SYM){
    if( SYM.CODE == ERREUR_TOKEN) {
        printf("erreur ligne %d colonne %d .\n", Ligne_Courante, Colonne_Courante);
        //exit(EXIT_FAILURE);
    }
    for(int i = 0;i < NUMBEROFTOKENS; i++) {
        if(ALLTOKENS_TEXT[i].CODE == SYM.CODE) {
            printf("%s\n",ALLTOKENS_TEXT[i].TOKEN_TEXT);
            break;
        }
    }
    Vider_NOM();
    return;
}

CODES_LEX code_mot_cle(char nom[]) {
    for (int i = DEBUTMOTCLE; i <= FINMOTCLE; i++) {
        if(strcmp(ALLTOKENS[i].TOKEN_NAME,nom) == 0){
            return ALLTOKENS[i].CODE;
        }
    }
    return NOTA_TOKEN;
}

void lire_mot() {
    NOM[Length_NOM] = Car_Cour;
    Length_NOM++;

    if(Car_Cour == '.') {
        Lire_Car();
        if(isdigit(Car_Cour)){
            lire_nombre();
            return;
        } else {
            SYM_COUR.CODE = ID_TOKEN;
            if(isalpha(Car_Cour) || Car_Cour == '.' || Car_Cour == '_') {
                NOM[Length_NOM] = Car_Cour;
                Length_NOM++;
            }
        }
    }
    // le max du longeur d'un nom est 100
    while( !feof(file) && (Length_NOM <= 100)){
        Lire_Car();
        if(isdigit(Car_Cour) || isalpha(Car_Cour) || Car_Cour == '.' || Car_Cour == '_') {
            NOM[Length_NOM] = Car_Cour;
            Length_NOM++;
        } else {
            NOM[Length_NOM] = '\0';
            strcpy(SYM_COUR.NOM, NOM);
            if(code_mot_cle(NOM)!=NOTA_TOKEN){
                SYM_COUR.CODE = code_mot_cle(NOM);
            } else{
                SYM_COUR.CODE = ID_TOKEN;
            } 
            break;
        }
    }
    /*
    si on quitté la boucle while donc c'est une erreur
    dépassement de len
    */
    if(Length_NOM > 100){
        SYM_COUR.CODE = ERREUR_TOKEN;
    }
    return;
}

void lire_special() {
    switch (Car_Cour)
    {
    case';':
        SYM_COUR.CODE = PV_TOKEN;
        Lire_Car();
        break;
    case'(':
        SYM_COUR.CODE = PARO_TOKEN;
        Lire_Car();
        break;
    case')':
        SYM_COUR.CODE = PARF_TOKEN;
        Lire_Car();
        break;
    case'-':
        Lire_Car();
        switch(Car_Cour){
            case '>':
                SYM_COUR.CODE = AFFTOD_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = MINUS_TOKEN;
                break;
        }
        break;
    case'+':
        SYM_COUR.CODE = PLS_TOKEN;
        Lire_Car();
        break;
    case'*':
        SYM_COUR.CODE = MULT_TOKEN;
        Lire_Car();
        break;
    case'/':
        SYM_COUR.CODE = DIV_TOKEN;
        Lire_Car();
        break;
    case'!':
        Lire_Car();
        switch(Car_Cour){
            case '=':
                SYM_COUR.CODE = DIFF_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = NEG_TOKEN;
                break;
        }
        break;
    case'~':
        SYM_COUR.CODE = TILD_TOKEN;
        Lire_Car();
        break;
    case':':
        SYM_COUR.CODE = DP_TOKEN;
        Lire_Car();
        break;
    case'?':
        SYM_COUR.CODE = INTER_TOKEN;
        Lire_Car();
        break;
    case'^':
        SYM_COUR.CODE = POWER_TOKEN;
        Lire_Car();
        break;
    case'<':
        Lire_Car();
        switch(Car_Cour){
            case '=':
                SYM_COUR.CODE = INFEG_TOKEN;
                Lire_Car();
                break;
            case '-':
                SYM_COUR.CODE = AFFTOG_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = INF_TOKEN;
                break;
        }
        break;
    case'>':
        Lire_Car();
        switch(Car_Cour){
            case '=':
                SYM_COUR.CODE = SUPEG_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = SUP_TOKEN;
                break;
        }
        break;
    case'=':
        Lire_Car();
        switch(Car_Cour){
            case '=':
                SYM_COUR.CODE = EQ_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = EG_TOKEN;
                break;
        }
        break;
    case'&':
        Lire_Car();
        switch(Car_Cour){
            case '&':
                SYM_COUR.CODE = DET_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = ET_TOKEN;
                break;
        }
        break;
    case'|':
        Lire_Car();
        switch(Car_Cour){
            case '|':
                SYM_COUR.CODE = DOU_TOKEN;
                Lire_Car();
                break;
            default:
                SYM_COUR.CODE = OU_TOKEN;
                break;
        }
        break;
    case ',':
        SYM_COUR.CODE = VIR_TOKEN;
        Lire_Car();
        break;
    case '$':
        SYM_COUR.CODE = DOLLAR_TOKEN;
        Lire_Car();
        break;
    case '{':
        SYM_COUR.CODE = ACCO_TOKEN;
        Lire_Car();
        break;
    case'}':
        SYM_COUR.CODE = ACCF_TOKEN;
        Lire_Car();
        break;
    case'[':
        SYM_COUR.CODE = BRO_TOKEN;
        Lire_Car();
        break;
    case ']':
        SYM_COUR.CODE = BRF_TOKEN;
        Lire_Car();
        break;
    case '%':
        Lire_Car();
        switch (Car_Cour)
        {
        case '%':
            SYM_COUR.CODE = MOD_TOKEN;
            Lire_Car();
            break;
        case 'i':
            Lire_Car();
            if(Car_Cour == 'n') {
                Lire_Car();
                if(Car_Cour == '%') {
                    SYM_COUR.CODE = IN_TOKEN;
                    Lire_Car(); 
                } else {
                    SYM_COUR.CODE = ERREUR_TOKEN;
                }
            } else {
                SYM_COUR.CODE = ERREUR_TOKEN;
            }
            break;
        default:
            SYM_COUR.CODE = ERREUR_TOKEN;
            break;
        }
        break;
    default:
        SYM_COUR.CODE = ERREUR_TOKEN;
        break;
    }
}

void lire_chaine() {
    bool isClosedQuotes = false;
    char simpleORdouble = Car_Cour;
    SYM_COUR.CODE = STRING_TOKEN;
    Lire_Car();
    while( !feof(file) && (Length_NOM <= 100) ) {
        if( Car_Cour == simpleORdouble && (NOM[Length_NOM-1] != 92) ) {
            isClosedQuotes = true;
            Lire_Car();
            break;
        } else {
            NOM[Length_NOM] = Car_Cour;
            Length_NOM++;
            Lire_Car();
        }
    }

    if(Length_NOM > 100 || !isClosedQuotes ) {
        SYM_COUR.CODE = ERREUR_TOKEN;
    }
}

// Either the fractional or
// the decimal part can be empty, but not both at once.
// Double : 1.5 15.e10 integer : 15L complex = 5i
//
// integers : [0-9]+ L
// complex :  [0-9]+ .? [0-9]* (e[+,-]?[0-9]+)? i
//             . [0-9]+ (e[+,-]?[0-9]+)? i
//             [0-9]+ (e[+,-]?[0-9]+)? i
// doubles : 
//              [0-9]+ .? [0-9]* (e[+,-]?[0-9]+)?
//              .[0-9]+ (e[+,-]?[0-9]+)?
//              [0-9]+ (e[+,-]?[0-9]+)?

void lire_exposant() {
    NOM[Length_NOM] = Car_Cour;
    Length_NOM++;
    Lire_Car();

    if(Car_Cour == '+' || Car_Cour == '-'){
        NOM[Length_NOM] = Car_Cour;
        Length_NOM++;
        Lire_Car();
    }

    if(isdigit(Car_Cour)){
        while(!feof(file) && Length_NOM <100 && isdigit(Car_Cour)) {
            NOM[Length_NOM] = Car_Cour;
            Length_NOM++;
            Lire_Car();
        }
    } else {
            SYM_COUR.CODE = ERREUR_TOKEN;
    }
}

void lire_nombre() {

    while(!feof(file) && Length_NOM <100 && isdigit(Car_Cour)) {
        NOM[Length_NOM] = Car_Cour;
        Length_NOM++;
        Lire_Car();
    }
    

    if(NOM[0] == '.') {
        if(Length_NOM >= 2){
            SYM_COUR.CODE = DOUBLE_TOKEN;
            if(Car_Cour == 'e') {
                lire_exposant();
            }
            switch (Car_Cour) {
                case 'i':
                    SYM_COUR.CODE = COMPLEX_TOKEN;
                    Lire_Car();
                    break;
                default:
                    SYM_COUR.CODE = DOUBLE_TOKEN;
                    break;
            }
        } else {
            SYM_COUR.CODE = ERREUR_TOKEN;
        }
    } else {
        switch(Car_Cour) {
        case '.':
            NOM[Length_NOM] = Car_Cour;
            Length_NOM++;
            Lire_Car();
            while(!feof(file) && Length_NOM <100 && isdigit(Car_Cour)) {
                NOM[Length_NOM] = Car_Cour;
                Length_NOM++;
                Lire_Car();
            }
            if(Car_Cour == 'e') {
                lire_exposant();
            }
            switch (Car_Cour) {
                case 'i':
                    SYM_COUR.CODE = COMPLEX_TOKEN;
                    Lire_Car();
                break;
                default:
                    SYM_COUR.CODE = DOUBLE_TOKEN;
                    break;
            }
            break;
        default:
            if(Car_Cour == 'e') {
                lire_exposant();
                switch (Car_Cour) {
                    case 'i':
                        SYM_COUR.CODE = COMPLEX_TOKEN;
                        Lire_Car();
                    break;
                    default:
                        SYM_COUR.CODE = DOUBLE_TOKEN;
                    break;
                }
            } else {
                switch (Car_Cour) {
                case 'L':
                    SYM_COUR.CODE = INTEGER_TOKEN;
                    Lire_Car();
                    break;
                case 'i':
                    SYM_COUR.CODE = COMPLEX_TOKEN;
                    Lire_Car();
                    break;
                default:
                    SYM_COUR.CODE = DOUBLE_TOKEN;
                    break;
                }
            }
            break;
        }
    }

    if(Length_NOM > 100 || isalpha(Car_Cour)){
        SYM_COUR.CODE = ERREUR_TOKEN;
    } else {
        strcpy(SYM_COUR.NOM, NOM);
    }

}

// pas de fin du commentaire ou fin de ligne ?
// si ######################### ??

void lire_commentaire() { 
    SYM_COUR.CODE = COM_TOKEN;
    Lire_Car();
    while(Car_Cour!='\n' &&  !feof(file) ) {
        Lire_Car();
    }
}

void Erreur_aff(Erreurs ERR){
    if(ERR < NOMBRE_ERREUR){
        printf("Erreur numero %d: %s , ligne : %d .\n",ERR,MES_ERR[ERR].MES,Ligne_Courante);
    }
    getchar();
    exit(-1);
}

//Analyseur Syntaxique
//Prototypes des fonctions d'analyseur syntaxique
void INSTRS();
void SS();
void S();
void APP();
void V();
void EXP();
void FUNCTION();
void CREATE_FACTOR();
void INTERHELP();
void HELP();
void PRINT();
void LEVELS();
void AEXP1();
void LIST();
void SUBSET_DATAFRAME();
void CREATE_DATAFRAME();
void AEXP2();
void REMOVE();
void A();
void EXP();
void FUNCTION();
void SM1();
void SE2();
void EE2();
void V2();
void SD11();
void SLD();
void FACT();
void TERM();
void EXPR1();
void V1();
void Vprime();
void RENAME();
void VAR2();
void VARS();
void BASIC_TYPE();
void LOG_OP();
void CV2();
void CV();
void VECTOR333();
void VECTOR33();
void VECTOR3();
void CS2();
void CS();
void VECTOR4();
void CN2();
void CN();
void CL2();
void CL();
void CNAMED_S2();
void CNAMED_L2();
void CNAMED_L();
void CNAMED_N2();
void CNAMED_N();
void CNAMED_NLS();
void CNAMED_NA();
void CNAMED_L();
void CNAMED_N();
void CNAMED_S();
void CNAMED_T();
void CNAMED();
void SMP();
void SMD4();
void SMP2();
void SMP3();
void SMD();
void SMD3();
void SMD2();
void SMD4();
void SMV();
void SMV2();
void STAT_FUNCTION();
void TYPE();
void TYPE2();
void TEST_TYPE();
void CONVERT();
void CREATE_MATRIX();
void CREATE_LIST();
void RC();
void VECTORS();
void VECTORS2();
void VECTOR2();
void TRANSPOSE();
void DIMENSION();
void SPEC_MATRIX_FUNCTION();
void FP();
void INDIVID_PER_LEVEL();
void SPEC_FACTOR_FUNC();
void COLS();
void COL();
void COLS2();
void COL2();
void SEQ();
void SEQPARAM();
void RSEQ();
void ELEMENT_NAMES();
void ASSIGN();
void VECTOR();
void IF();
void ELSE();
void REAPEAT();
void WHILE();
void FOR();
void IFTEST();
void COND();
void CONDTERM();
void WHILE();
void IGNORERSEPARATEUR();
void REPEAT();
void ELSEIF();
void SREPEAT(CODES_LEX code);
void IGNORENEWLINE();
void TESTERSAMELINE();
int VERIFIER();
void ARGUMENT();
void FUNCTION();

void Test_Symbole(CODES_LEX CODE_LEX,Erreurs CODE_ERR) {
    if(SYM_COUR.CODE == SEPARATEUR_TOKEN){
        IGNORERSEPARATEUR();
        if(SYM_COUR.CODE == CODE_LEX) {
        Sym_Suiv();
        }else{
            Erreur_aff(CODE_ERR);
        }
    }
    else if(SYM_COUR.CODE == CODE_LEX) {
        Sym_Suiv();
    }
    else {
        Erreur_aff(CODE_ERR);
    }
}

void SS(){
    do{
        //printf("waaah\n");
        //IGNORERSEPARATEUR();
        switch(SYM_COUR.CODE){
        case IF_TOKEN: IF(); break;
        case WHILE_TOKEN: WHILE();break; 
        case REPEAT_TOKEN: REPEAT();  break;
        default: INSTRS();break;
        }
    }while(!feof(file));
}

void  INSTRS(){
    int i = 0,j=0;

    CODE_TEMP = 7;
    do{ 
       CODE_TEMP = (i == 0 ? 7: SYM_COUR.CODE);
        
        i==0?1:Sym_Suiv();
        i++;
        IGNORERSEPARATEUR();
        S();
        IGNORERSEPARATEUR();
    }while( SYM_COUR.CODE == NEWLINE_TOKEN );
    
    j= VERIFIER();

    if(j==1 && CODE_VER == PV_TOKEN){return;}
    if(CODE_TEMP != NEWLINE_TOKEN ){
        switch(SYM_COUR.CODE){
        case PV_TOKEN:CODE_VER = PV_TOKEN; INSTRS();break;        
        default:Erreur_aff(INST_ERR);break;
     }
    }
}


void S() {
    switch (SYM_COUR.CODE) {
        case INTER_TOKEN:INTERHELP() ;break;
        case HELP_TOKEN:HELP();break;
        case PRINT_TOKEN:PRINT(); break;
        case LEVELS_TOKEN:LEVELS(); AEXP1();break;
        case LS_TOKEN:LIST();break;
        case SUBSET_TOKEN:
        case ATTACH_TOKEN:
        case DETACH_TOKEN: SUBSET_DATAFRAME(); AEXP2() ;break;
        case RM_TOKEN:REMOVE() ;break;
        case NAMES_TOKEN:ELEMENT_NAMES() ;break;
        case ROWNAMES_TOKEN:
        case COLNAMES_TOKEN:A() ;break;
        
        //EXP
        case ID_TOKEN: 
        case TRUE_TOKEN:
        case FALSE_TOKEN:
        case INTEGER_TOKEN:
        case DOUBLE_TOKEN:
        case COMPLEX_TOKEN:
        case C_TOKEN:
        case MODE_TOKEN:
        case CAT_TOKEN:
        case LENGTH_TOKEN:
        case LOG2_TOKEN:
        case LOG10_TOKEN:
        case EXP_TOKEN:
        case COS_TOKEN:
        case SIN_TOKEN:
        case TAN_TOKEN:
        case ACOS_TOKEN:
        case ASIN_TOKEN:
        case ATAN_TOKEN:
        case ABS_TOKEN:
        case SQRT_TOKEN:
        case MAX_TOKEN:
        case MIN_TOKEN:
        case RANGE_TOKEN:
        case SUM_TOKEN:
        case PROD_TOKEN:
        case MEAN_TOKEN:
        case SD_TOKEN:
        case VAR_TOKEN:
        case SORT_TOKEN:
        case TYPEOF_TOKEN:
        case CLASS_TOKEN:
        case IS_NUMERIC_TOKEN:
        case IS_CHARACTER_TOKEN:
        case IS_LOGICAL_TOKEN:
        case IS_COMPLEX_TOKEN:
        case IS_NA_TOKEN:
        case IS_NAN_TOKEN:
        case IS_FACTOR_TOKEN:
        case IS_DATA_FRAME_TOKEN:
        case AS_NUMERIC_TOKEN:
        case AS_CHARACTER_TOKEN:
        case AS_LOGICAL_TOKEN:
        case AS_FACTOR_TOKEN:
        case AS_DATA_FRAME_TOKEN:
        case RBIND_TOKEN:
        case CBIND_TOKEN:
        case MATRIX_TOKEN:
        case T_TOKEN:
        case NCOL_TOKEN:
        case NROW_TOKEN:
        case DIM_TOKEN:
        case ROWSUMS_TOKEN:
        case COLSUMS_TOKEN:
        case COLMEANS_TOKEN:
        case ROWMEANS_TOKEN:
        case APPLY_TOKEN:
        case FACTOR_TOKEN:
        case SUMMARY_TOKEN:
        case TAPPLY_TOKEN:
        case TABLE_TOKEN:
        case DATAFRAME_TOKEN:
        case SEQ_TOKEN:
        case REP_TOKEN:
        case SEQUENCE_TOKEN:
        case RNORM_TOKEN:
        case REXP_TOKEN:
        case RGAMMA_TOKEN:
        case RNBINOM_TOKEN:
        case RUNIF_TOKEN:
        case RGEOM_TOKEN:
        case RCAUCHY_TOKEN:
        case RPOIS_TOKEN:
        case RF_TOKEN:
        case RT_TOKEN:
        case RLOGIS_TOKEN:
        case DNORM_TOKEN:
        case DEXP_TOKEN:
        case DGAMMA_TOKEN:
        case DNBINOM_TOKEN:
        case DUNIF_TOKEN:
        case DGEOM_TOKEN:
        case DCAUCHY_TOKEN:
        case DPOIS_TOKEN:
        case DF_TOKEN:
        case DT_TOKEN:
        case DLOGIS_TOKEN:
        case PNORM_TOKEN:
        case PEXP_TOKEN:
        case PGAMMA_TOKEN:
        case PNBINOM_TOKEN:
        case PUNIF_TOKEN:
        case PGEOM_TOKEN:
        case PCAUCHY_TOKEN:
        case PPOIS_TOKEN:
        case PF_TOKEN:
        case PT_TOKEN:
        case PLOGIS_TOKEN:
        case QNORM_TOKEN:
        case QEXP_TOKEN:
        case QGAMMA_TOKEN:
        case QNBINOM_TOKEN:
        case QUNIF_TOKEN:
        case QGEOM_TOKEN:
        case QCAUCHY_TOKEN:
        case QPOIS_TOKEN:
        case QF_TOKEN:
        case QT_TOKEN:
        case QLOGIS_TOKEN:
        case LIST_TOKEN:
        
        // EXP va traiter tous ces tokens precedant
        EXP();
        break;

        case NEWLINE_TOKEN:/*Sym_Suiv();S();*/ break;
        case SEPARATEUR_TOKEN: break;
        /*case IF_TOKEN: IF(); break;
        case WHILE_TOKEN: WHILE();break; 
        case REPEAT_TOKEN: REPEAT();  break; */

    default:/* printf("SORTIT DE S()\n")*/;break;

    }
}
void IGNORERSEPARATEUR(){
    while(/*SYM_COUR.CODE == NEWLINE_TOKEN ||*/ SYM_COUR.CODE == SEPARATEUR_TOKEN){
        Sym_Suiv();
    }
    Vider_NOM();
}

void IGNORERNEWLINE(){
    while(SYM_COUR.CODE == NEWLINE_TOKEN){
        Sym_Suiv();
    }
    Vider_NOM();
}
int VERIFIER(){
    switch(SYM_COUR.CODE){
        case IF_TOKEN:
        case WHILE_TOKEN: 
        case BREAK_TOKEN:
        case REPEAT_TOKEN: return 1;
        default: return 0;
        }
}

void WHILE(){
    Test_Symbole(WHILE_TOKEN,WHILE_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    COND();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    INSTRS();
    IGNORERSEPARATEUR();
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);

}

void IF() {
    Test_Symbole(IF_TOKEN,IF_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    COND();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    IGNORERSEPARATEUR(); 
    switch(SYM_COUR.CODE){
        case BREAK_TOKEN:Test_Symbole(BREAK_TOKEN,BREAK_ERR);break;
        default: INSTRS();break;
    }
    SYM_COUR.CODE==BREAK_TOKEN?Test_Symbole(BREAK_TOKEN,BREAK_ERR):1;
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
   // AfficherToken(SYM_COUR);
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    switch(SYM_COUR.CODE){
        case ELSE_TOKEN : ELSE();break;
        case ELSEIF_TOKEN:ELSEIF();break;
        default:  break;
    }

}


void TESTERSAMELINE(){
    IGNORERSEPARATEUR();
    switch(SYM_COUR.CODE){
        case NEWLINE_TOKEN: IGNORERNEWLINE();break;
        case PV_TOKEN:AfficherToken(SYM_COUR); Sym_Suiv();break;
        default: Erreur_aff(INST_ERR);break;
    }
}

void ELSE() {
    Test_Symbole(ELSE_TOKEN,ELSE_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    IGNORERSEPARATEUR(); 
    switch(SYM_COUR.CODE){
        case BREAK_TOKEN:Test_Symbole(BREAK_TOKEN,BREAK_ERR);break;
        default: INSTRS();break;
    }
    SYM_COUR.CODE==BREAK_TOKEN?Test_Symbole(BREAK_TOKEN,BREAK_ERR):1;
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
   //AfficherToken(SYM_COUR);
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();


}

void ELSEIF(){
    Test_Symbole(ELSEIF_TOKEN,ELSEIF_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    COND();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    IGNORERSEPARATEUR(); 
    switch(SYM_COUR.CODE){
        case BREAK_TOKEN:Test_Symbole(BREAK_TOKEN,BREAK_ERR);break;
        default: INSTRS();break;
    }
    SYM_COUR.CODE==BREAK_TOKEN?Test_Symbole(BREAK_TOKEN,BREAK_ERR):1;
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
   // AfficherToken(SYM_COUR);
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    switch(SYM_COUR.CODE){
        case ELSE_TOKEN :ELSE();break;
        case ELSEIF_TOKEN: ELSEIF();break;
        default:Erreur_aff(ELSE_ERR); break;
    }

}

void HELP() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch (SYM_COUR.CODE) {
    case STRING_TOKEN:
    case ID_TOKEN:
        Sym_Suiv();
        break;            
    default:
        Erreur_aff(ID_STRING_ERR);
        break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}



void REPEAT(){
    Sym_Suiv();
   // AfficherToken(SYM_COUR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
   // AfficherToken(SYM_COUR);
    INSTRS();
    
    
    //AfficherToken(SYM_COUR);
    //TESTERSAMELINE();
    //AfficherToken(SYM_COUR);
    
    Test_Symbole(IF_TOKEN,IF_ERR);
    //AfficherToken(SYM_COUR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    //AfficherToken(SYM_COUR);
    COND();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
   // AfficherToken(SYM_COUR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
   //IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    //AfficherToken(SYM_COUR);
   
    SYM_COUR.CODE == BREAK_TOKEN?1:INSTRS();
    
    Test_Symbole(BREAK_TOKEN,BREAK_ERR);
    //AfficherToken(SYM_COUR);
    
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    //AfficherToken(SYM_COUR);
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}


void FUNCTION(){
    Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
    
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    ARGUMENT();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    Test_Symbole(ACCO_TOKEN,ACCO_ERR);
    IGNORERSEPARATEUR(); 
    switch(SYM_COUR.CODE){
        case BREAK_TOKEN:Test_Symbole(BREAK_TOKEN,BREAK_ERR);break;
        default: INSTRS();break;
    }
    SYM_COUR.CODE==BREAK_TOKEN?Test_Symbole(BREAK_TOKEN,BREAK_ERR):1;
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
    Test_Symbole(ACCF_TOKEN,ACCF_ERR);
    IGNORERNEWLINE();
    IGNORERSEPARATEUR();
}

void ARGUMENT(){
       //AfficherToken(SYM_COUR);
       Test_Symbole(ID_TOKEN,ID_ERR);
       SYM_COUR.CODE == EG_TOKEN ?Sym_Suiv():1;
    while(SYM_COUR.CODE  == VIR_TOKEN){
       Sym_Suiv();
       //AfficherToken(SYM_COUR);
       Test_Symbole(ID_TOKEN,ID_ERR);
       SYM_COUR.CODE == EG_TOKEN ?Sym_Suiv():1;
    }
    //AfficherToken(SYM_COUR);
    SYM_COUR.CODE == PARF_TOKEN ? 1:Erreur_aff(FUNCTION_ERR);
}

void INTERHELP() {
    Sym_Suiv();
    switch (SYM_COUR.CODE) {
    case STRING_TOKEN:
    case ID_TOKEN:
        Sym_Suiv();
    break;
            
    default:
        Erreur_aff(ID_STRING_ERR);
        break;
    }
}

void PRINT() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void LEVELS() {
    Test_Symbole(LEVELS_TOKEN,LEVELS_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void AEXP1() {
    switch (SYM_COUR.CODE) {
    case AFFTOG_TOKEN:
    case EG_TOKEN:
        ASSIGN();
        VECTOR();
        break;
    default:
        // epsilon
        break;
    }

}

void ASSIGN() {
    switch (SYM_COUR.CODE) {
    case AFFTOG_TOKEN:
    case EG_TOKEN:
        Sym_Suiv();
        break;
    
    default:
        Erreur_aff(ASSIGN_ERR);
        break;
    }
}

void VECTOR() {
    Test_Symbole(C_TOKEN,C_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    VECTOR2();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void VECTOR2() {
    switch(SYM_COUR.CODE) {
        case TRUE_TOKEN:
        case FALSE_TOKEN:
            CL();
        break;

        case INTEGER_TOKEN:
        case DOUBLE_TOKEN:
            CN();
            VECTOR4();
        break;

        case STRING_TOKEN:
            CS();
            VECTOR3();
        break;
        
        case C_TOKEN:
            CV();
        break;
        case ID_TOKEN:
            CNAMED();
        default:
            Erreur_aff(VECTOR2_ERR);
        break;
    }
}

void CNAMED() {
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(EG_TOKEN,EG_ERR);
    CNAMED_T();
}

void CNAMED_T() {
    switch(SYM_COUR.CODE) {
        case NA_TOKEN:
            Sym_Suiv();
            CNAMED_NA();
        break;
        
        case DOUBLE_TOKEN:
        case INTEGER_TOKEN:
            CNAMED_N();
        break;
        
        case TRUE_TOKEN:
        case FALSE_TOKEN:
            CNAMED_L();
        break;

        case STRING_TOKEN:
            CNAMED_S();
        break;
        default:
            Erreur_aff(NLSNA_ERR);
        break;
    }
}

void CNAMED_NA() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CNAMED_NLS();
        break;
        default:
        //epsilon
        break;
    }
}

void CNAMED_NLS() {
    switch (SYM_COUR.CODE)
    {
        case DOUBLE_TOKEN:
        case INTEGER_TOKEN:
            CNAMED_N();
        break;
        
        case TRUE_TOKEN:
        case FALSE_TOKEN:
            CNAMED_L();
        break;

        case STRING_TOKEN:
            CNAMED_S();
    default:
        Erreur_aff(NLS_ERR);
        break;
    }
}

void CNAMED_N() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
    case INTEGER_TOKEN:
        CNAMED_N2();
        break;

    default:
        Erreur_aff(NUMERIC_ERR);
        break;
    }
}

void CNAMED_N2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CNAMED_N();
        break;

        default:
        //epsilon
        break;
    }
}

void CNAMED_L() {
    switch (SYM_COUR.CODE)
    {
    case TRUE_TOKEN:
    case FALSE_TOKEN:
        CNAMED_L2();
        break;

    default:
        Erreur_aff(TRUEFALSE_ERR);
        break;
    }
}

void CNAMED_L2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CNAMED_L();
        break;

        default:
        //epsilon
        break;
    }
}

void CNAMED_S() {
    switch (SYM_COUR.CODE)
    {
    case TRUE_TOKEN:
    case FALSE_TOKEN:
        CNAMED_S2();
        break;

    default:
        Erreur_aff(STRING_ERR);
        break;
    }
}

void CNAMED_S2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CNAMED_S();
        break;

        default:
        //epsilon
        break;
    }
}

void CL() {
    switch(SYM_COUR.CODE) {
        case TRUE_TOKEN:
        case FALSE_TOKEN:
            Sym_Suiv();
            CL2();
        break;

        default:
            Erreur_aff(TRUEFALSE_ERR);
        break;
    }
    
}

void CL2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CL();
        break;
        default:
        //epsilon
        break;
    }
}

void CN() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
    case INTEGER_TOKEN:
        Sym_Suiv();
        CN2();
        break;
    
    default:
        Erreur_aff(NUMERIC_ERR);
        break;
    }
}

void CN2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CN();
        break;
        default:
        //epsilon
        break;
    }
}

void VECTOR4() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CL();
        break;
        default:
        //epsilon
        break;
    }
}

void CS() {
    switch (SYM_COUR.CODE)
    {
    case STRING_TOKEN:
        Sym_Suiv();
        CS2();
        break;
    
    default:
        Erreur_aff(STRING_ERR);
        break;
    }
}

void CS2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CS();
        break;
        default:
        //epsilon
        break;
    }
}

void VECTOR3() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        VECTOR33();
        break;
    
    default:
        //epsilon
        break;
    }
}

void VECTOR33() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
    case INTEGER_TOKEN:
        CN();
        VECTOR333();
    case TRUE_TOKEN:
    case FALSE_TOKEN:
        CL();
        break;
    default:
        Erreur_aff(NL_ERR);
        break;
    }
}

void VECTOR333() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        CL();
        break;
    
    default:
    //epsilon
        break;
    }
}

void CV() {
    VECTOR();
    CV2();
}

void CV2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            CV();
        break;
        default:
        //epsilon
        break;
    }
}

void LIST() {
    Test_Symbole(LS_TOKEN,LS_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void SUBSET_DATAFRAME() {
    switch (SYM_COUR.CODE)
    {
    case SUBSET_TOKEN:
        Sym_Suiv();
        Test_Symbole(PARO_TOKEN,PARO_ERR);
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(VIR_TOKEN,VIR_ERR);
        Test_Symbole(ID_TOKEN,ID_ERR);
        LOG_OP();
        BASIC_TYPE();
        Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;

    case DETACH_TOKEN:
    case ATTACH_TOKEN:
        Sym_Suiv();
        Test_Symbole(PARO_TOKEN,PARO_ERR);
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
    
    default:
        Erreur_aff(SUBSET_DATAFRAME_ERR);
        break;
    }
}

void LOG_OP() {
    switch (SYM_COUR.CODE)
    {
    case EQ_TOKEN:
    case DIFF_TOKEN:
    case SUPEG_TOKEN:
    case SUP_TOKEN:
    case INFEG_TOKEN:
    case INF_TOKEN:
        Sym_Suiv();
        break;
    
    default:
        Erreur_aff(LOG_OP_ERR);
        break;
    }
}

void BASIC_TYPE() {
    switch (SYM_COUR.CODE)
    {
    case TRUE_TOKEN:
    case FALSE_TOKEN:
    case DOUBLE_TOKEN:
    case INTEGER_TOKEN:
    case STRING_TOKEN:
    case COMPLEX_TOKEN:
        Sym_Suiv();
        break;
    
    default:
        Erreur_aff(BASIC_TYPE_ERR);
        break;
    }
}

void AEXP2() {
    switch (SYM_COUR.CODE) {
    case AFFTOG_TOKEN:
    case EG_TOKEN:
        ASSIGN();
        Test_Symbole(ID_TOKEN,ID_ERR);
        break;
    default:
        // epsilon
        break;
    }
}

void REMOVE() {
    Test_Symbole(RM_TOKEN,RM_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    VARS();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void VARS() {
    Test_Symbole(ID_TOKEN,ID_ERR);
    VAR2();
}

void VAR2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            Test_Symbole(ID_TOKEN,ID_ERR);
        break;
        default:
        //epsilon
        break;
    }
}

void ELEMENT_NAMES() {
    Test_Symbole(NAMES_TOKEN,NAMES_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void A() {
    switch (SYM_COUR.CODE)
    {
    case ROWNAMES_TOKEN:
    case COLNAMES_TOKEN:
        Sym_Suiv();
        RENAME();
        ASSIGN();
        VECTOR();
        break;
    
    default:
        Erreur_aff(A_ERR);
        break;
    }
}

void RENAME() {
    switch (SYM_COUR.CODE)
    {
    case ROWNAMES_TOKEN:
    case COLNAMES_TOKEN:
        Sym_Suiv();
        Test_Symbole(PARO_TOKEN,PARO_ERR);
        Test_Symbole(ID_TOKEN,ID_ERR);
        Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
    default:
        Erreur_aff(RENAME_ERR);
        break;
    }
}

void EXP() {
    switch(SYM_COUR.CODE) {
        case ID_TOKEN:
       
            V();
        break;
        case TRUE_TOKEN:
        case FALSE_TOKEN:
        case INTEGER_TOKEN:
        case DOUBLE_TOKEN:
        case COMPLEX_TOKEN:
            BASIC_TYPE();
        break;

        case C_TOKEN:
            VECTOR();
        break;
        
        case MODE_TOKEN:
        case CAT_TOKEN:
        case LENGTH_TOKEN:
        case LOG2_TOKEN:
        case LOG10_TOKEN:
        case EXP_TOKEN:
        case COS_TOKEN:
        case SIN_TOKEN:
        case TAN_TOKEN:
        case ACOS_TOKEN:
        case ASIN_TOKEN:
        case ATAN_TOKEN:
        case ABS_TOKEN:
        case SQRT_TOKEN:
            FUNCTION();
        break;

        case MAX_TOKEN:
        case MIN_TOKEN:
        case RANGE_TOKEN:
        case SUM_TOKEN:
        case PROD_TOKEN:
        case MEAN_TOKEN:
        case SD_TOKEN:
        case VAR_TOKEN:
        case SORT_TOKEN:
            STAT_FUNCTION();
        break;  


        case TYPEOF_TOKEN:
        case CLASS_TOKEN:
            TYPE();
        break;

        case IS_NUMERIC_TOKEN:
        case IS_CHARACTER_TOKEN:
        case IS_LOGICAL_TOKEN:
        case IS_COMPLEX_TOKEN:
        case IS_NA_TOKEN:
        case IS_NAN_TOKEN:
        case IS_FACTOR_TOKEN:
        case IS_DATA_FRAME_TOKEN:
            TEST_TYPE();
        break;

        case AS_NUMERIC_TOKEN:
        case AS_CHARACTER_TOKEN:
        case AS_LOGICAL_TOKEN:
        case AS_FACTOR_TOKEN:
        case AS_DATA_FRAME_TOKEN:
            CONVERT();
        break;

        case RBIND_TOKEN:
        case CBIND_TOKEN:
        case MATRIX_TOKEN:
            CREATE_MATRIX();
        break;

        case T_TOKEN:
            TRANSPOSE();
        break;

        case NCOL_TOKEN:
        case NROW_TOKEN:
        case DIM_TOKEN:
            DIMENSION();
        break;

        case ROWSUMS_TOKEN:
        case COLSUMS_TOKEN:
        case COLMEANS_TOKEN:
        case ROWMEANS_TOKEN:
        case APPLY_TOKEN:
            SPEC_MATRIX_FUNCTION();
        break;

        case FACTOR_TOKEN:
            CREATE_FACTOR();
        break;

        case SUMMARY_TOKEN:
            INDIVID_PER_LEVEL();
        break;

        case TAPPLY_TOKEN:
        case TABLE_TOKEN:
            SPEC_FACTOR_FUNC();
        break;

        case DATAFRAME_TOKEN:
            CREATE_DATAFRAME();
        break;

        case SEQ_TOKEN:
        case REP_TOKEN:
        case SEQUENCE_TOKEN:
            SEQ();
        break;

        case RNORM_TOKEN:
        case REXP_TOKEN:
        case RGAMMA_TOKEN:
        case RNBINOM_TOKEN:
        case RUNIF_TOKEN:
        case RGEOM_TOKEN:
        case RCAUCHY_TOKEN:
        case RPOIS_TOKEN:
        case RF_TOKEN:
        case RT_TOKEN:
        case RLOGIS_TOKEN:

        case DNORM_TOKEN:
        case DEXP_TOKEN:
        case DGAMMA_TOKEN:
        case DNBINOM_TOKEN:
        case DUNIF_TOKEN:
        case DGEOM_TOKEN:
        case DCAUCHY_TOKEN:
        case DPOIS_TOKEN:
        case DF_TOKEN:
        case DT_TOKEN:
        case DLOGIS_TOKEN:

        case PNORM_TOKEN:
        case PEXP_TOKEN:
        case PGAMMA_TOKEN:
        case PNBINOM_TOKEN:
        case PUNIF_TOKEN:
        case PGEOM_TOKEN:
        case PCAUCHY_TOKEN:
        case PPOIS_TOKEN:
        case PF_TOKEN:
        case PT_TOKEN:
        case PLOGIS_TOKEN:

        case QNORM_TOKEN:
        case QEXP_TOKEN:
        case QGAMMA_TOKEN:
        case QNBINOM_TOKEN:
        case QUNIF_TOKEN:
        case QGEOM_TOKEN:
        case QCAUCHY_TOKEN:
        case QPOIS_TOKEN:
        case QF_TOKEN:
        case QT_TOKEN:
        case QLOGIS_TOKEN:
            RSEQ();
        break;

        case LIST_TOKEN:
            CREATE_LIST();
        break;

        default: 
            Erreur_aff(EXP_ERR);
        break;
    }
}

void V() {
    switch(SYM_COUR.CODE) {
        case ID_TOKEN:
             
            Sym_Suiv();
            
            Vprime();
            break;
        default:
            Erreur_aff(ID_ERR);
        break;
    }
}

void Vprime() {
    switch(SYM_COUR.CODE) {
        case EG_TOKEN:switcher=-1;
        case AFFTOG_TOKEN: 
        case DOLLAR_TOKEN:
                
            V1();
        break;
        case BRO_TOKEN:
            Sym_Suiv();
            V2();
            Test_Symbole(BRF_TOKEN,BRF_ERR);
        break;

        default: Erreur_aff(ID_ERR); break;
    }
}

void V1() {
    switch (SYM_COUR.CODE)
    {
        case AFFTOG_TOKEN:
        case EG_TOKEN:
            ASSIGN(); 
            
            EXPR1();
        break;
        case DOLLAR_TOKEN:
            Sym_Suiv();
            SLD();
        break;
    default:Erreur_aff(ID_ERR); break;
    }
}
//Ajouter
void COND(){
    
    CONDTERM();
    while(SYM_COUR.CODE == EQ_TOKEN){
            Sym_Suiv();
            CONDTERM();
        }

}

void CONDTERM(){
    EXPR1();
	switch(SYM_COUR.CODE){
		case EG_TOKEN:     Test_Symbole(EG_TOKEN,EG_ERR);
							break;
		case DIFF_TOKEN:   Test_Symbole(DIFF_TOKEN,DIFF_TOKEN);
							break;
		case INF_TOKEN:    Test_Symbole(INF_TOKEN,INF_TOKEN);
							break;
		case SUP_TOKEN:    Test_Symbole(SUP_TOKEN,SUP_TOKEN);
							break;
		case INFEG_TOKEN : Test_Symbole(INFEG_TOKEN,INFEG_TOKEN);
							break;
		case SUPEG_TOKEN : Test_Symbole(SUPEG_TOKEN,SUPEG_TOKEN);
							
							break;
		default:  break;
	}
    EXPR1();
}

void EXPR1(){
    TERM();
    while(SYM_COUR.CODE == PLS_TOKEN || SYM_COUR.CODE == MINUS_TOKEN){
        Sym_Suiv();
        TERM();
    }

}
void TERM(){
    FACT();
    while(SYM_COUR.CODE == MULT_TOKEN || SYM_COUR.CODE == DIV_TOKEN){
        Sym_Suiv();
        FACT();
    }

}

void FACT(){
    switch(SYM_COUR.CODE){
        case ID_TOKEN: Test_Symbole(ID_TOKEN,ID_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,NUMERIC_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,NUMERIC_ERR);break;
        case PARO_TOKEN: Sym_Suiv(); EXPR1(); Test_Symbole(PARF_TOKEN,PARF_ERR);break;
        case FUNCTION_TOKEN: if(switcher!=-1){FUNCTION();break;}
                             else{Erreur_aff(FUNCTION_ERR);break;}

        default:/*Erreur_aff(A_ERR);*/ break;
    }
}


void SLD() {
    Test_Symbole(ID_TOKEN,ID_ERR);
    SD11();
}

void SD11() {
    switch(SYM_COUR.CODE) {
        case EQ_TOKEN:
        case DIFF_TOKEN:
        case SUPEG_TOKEN:
        case SUP_TOKEN:
        case INFEG_TOKEN:
        case INF_TOKEN:
            LOG_OP();
            BASIC_TYPE();
        break;
        default:
        //epsilon
        break;
    }
}

void V2() {
    switch(SYM_COUR.CODE) {
        case MINUS_TOKEN:
            Sym_Suiv();
            EE2();
        break;
        
        case ID_TOKEN:
        case NEG_TOKEN:
        case IS_NA_TOKEN:
            SE2();
        break;

        case DOUBLE_TOKEN:
        case VIR_TOKEN:
        case C_TOKEN:
            SM1();
        break;

        /*case DOUBLE_TOKEN:
        case STRING_TOKEN:
        case ID_TOKEN:

        break;*/
    }
}

void EE2() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
    break;

    case C_TOKEN:
        Test_Symbole(C_TOKEN,C_ERR);
        Test_Symbole(PARO_TOKEN,PARO_ERR);
        Test_Symbole(VIR_TOKEN,VIR_ERR);
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        Test_Symbole(PARF_TOKEN,PARF_ERR);
    break;
    
    case PARO_TOKEN:
        Test_Symbole(PARO_TOKEN,PARO_ERR);
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        Test_Symbole(DP_TOKEN,DP_ERR);
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        Test_Symbole(PARF_TOKEN,PARF_ERR);
    default:
        Erreur_aff(DC_ERR);
        break;
    }
}

void SE2() {
    switch(SYM_COUR.CODE) {
        case ID_TOKEN:
            Sym_Suiv();
            LOG_OP();
            BASIC_TYPE();
        break;
        case NEG_TOKEN:
            Sym_Suiv();
            Test_Symbole(IS_NA_TOKEN,IS_NA_ERR);
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(ID_TOKEN,ID_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
        case IS_NA_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(ID_TOKEN,ID_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
        default:
            Erreur_aff(ID_NEG_IS_NA_ERR);
        break;
    }
}

void SM1() {
    switch(SYM_COUR.CODE) {
        case DOUBLE_TOKEN:
            SMD();
        break;

        case VIR_TOKEN:
            SMP();
        break;
        
        case C_TOKEN:
            SMV();
        break;
        default:
            Erreur_aff(DOUBLE_VIR_C_ERR);
        break;
    }
}

void SMD() {
    Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
    Test_Symbole(VIR_TOKEN,VIR_ERR);
    SMD2();
}

void SMD2() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        break;
    case DP_TOKEN:
        Sym_Suiv();
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        SMD3();
    default:
    //epsilon
        break;
    }

}

void SMV() {
    VECTOR();
    SMV2();
}

void SMV2() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        VECTOR();
        break;
    
    default:
    //epsilon
        break;
    }
}

void SMP() {
    Test_Symbole(VIR_TOKEN,VIR_ERR);
    SMP2();
}

void SMP2() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
        Sym_Suiv();
        SMP3();
        break;
    case C_TOKEN:
        VECTOR();
        break;
    default:
        Erreur_aff(DOUBLE_C_TOKEN);
        break;
    }
}

void SMP3() {
    switch(SYM_COUR.CODE) {
        case DP_TOKEN:
            Sym_Suiv();
            Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        break;
        default:
            //epsilon
            break;
    }
}

void SMD3() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        SMD4();
        break;
    
    default:
    //epsilon
        break;
    }
}

void SMD4() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
        Sym_Suiv();
        Test_Symbole(DP_TOKEN,DP_ERR);
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        break;
    
    default:
    //epsilon
        break;
    }
}



void STAT_FUNCTION() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void TYPE() {
    switch(SYM_COUR.CODE) {
        case TYPEOF_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            TYPE2();
            Test_Symbole(PARF_TOKEN,PARF_ERR);
            break;
        case CLASS_TOKEN:
            Sym_Suiv();
            Test_Symbole(ID_TOKEN,ID_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
            break;
    }
}

void TYPE2() {
    switch (SYM_COUR.CODE)
    {
    case DOUBLE_TOKEN:
    case INTEGER_TOKEN:
    case TRUE_TOKEN:
    case FALSE_TOKEN:
    case COMPLEX_TOKEN:
    case ID_TOKEN:
        Sym_Suiv();
        break;
    
    default:
        Erreur_aff(BASIC_ID_ERR);
        break;
    }
}

void TEST_TYPE() {
    switch(SYM_COUR.CODE) {
        case IS_NUMERIC_TOKEN:
        case IS_CHARACTER_TOKEN:
        case IS_LOGICAL_TOKEN:
        case IS_COMPLEX_TOKEN:
        case IS_NA_TOKEN:
        case IS_NAN_TOKEN:
        case IS_FACTOR_TOKEN:
        case IS_DATA_FRAME_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(ID_TOKEN,ID_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;        
    }
}

void CONVERT() {
    switch(SYM_COUR.CODE) {
        case AS_NUMERIC_TOKEN:
        case AS_CHARACTER_TOKEN:
        case AS_LOGICAL_TOKEN:
        case AS_FACTOR_TOKEN:
        case AS_DATA_FRAME_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(ID_TOKEN,ID_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;        
    }
}

void CREATE_MATRIX() {
    switch(SYM_COUR.CODE) {
        case RBIND_TOKEN:
        case CBIND_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            RC();
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
        case MATRIX_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(DATA_TOKEN,DATA_ERR);
            Test_Symbole(EG_TOKEN,EG_ERR);
            VECTOR();
            Test_Symbole(VIR_TOKEN,VIR_ERR);
            Test_Symbole(EG_TOKEN,EG_ERR);
            Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
            Test_Symbole(VIR_TOKEN,VIR_ERR);
            Test_Symbole(NCOL_TOKEN,NCOL_ERR);
            Test_Symbole(EG_TOKEN,EG_ERR);
            Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
            Test_Symbole(VIR_TOKEN,VIR_ERR);
            Test_Symbole(BYROW_TOKEN,BYROW_ERR);
            switch (SYM_COUR.CODE)
            {
            case TRUE_TOKEN:
            case FALSE_TOKEN:
                Sym_Suiv();
                break;
            
            default:
                Erreur_aff(TRUEFALSE_ERR);
                break;
            }
            Test_Symbole(VIR_TOKEN,VIR_ERR);
            Test_Symbole(DIMNAMES_TOKEN,DIMNAMES_ERR);
            Test_Symbole(EG_TOKEN,EG_ERR);
            Test_Symbole(LIST_TOKEN,LIST_ERR);
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            VECTORS();
            Test_Symbole(PARO_TOKEN,PARF_ERR);
        break;
    }
}

void RC() {
    VARS();
    VECTORS();
}

void VECTORS() {
    VECTOR();
    VECTORS2();
}

void VECTORS2() {
    switch(SYM_COUR.CODE) {
        case VIR_TOKEN:
            Sym_Suiv();
            VECTORS();
        break;
        default:
        //epsilon
        break;
    }
}

void TRANSPOSE() {
    Test_Symbole(T_TOKEN,T_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}


void DIMENSION() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);       
}

void SPEC_MATRIX_FUNCTION() {
    switch (SYM_COUR.CODE)
    {
    case ROWSUMS_TOKEN:
    case COLSUMS_TOKEN:
    case COLMEANS_TOKEN:
    case ROWMEANS_TOKEN:
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);  
    break;
    case APPLY_TOKEN:
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(VIR_TOKEN,VIR_ERR);
    APP();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    default:
        break;
    }
}

void APP() {
    Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
    STAT_FUNCTION();
}

void CREATE_FACTOR() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    FP();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void FP() {
    VECTOR();
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(LEVELS_TOKEN,LEVELS_ERR);
    Test_Symbole(EG_TOKEN,EG_ERR);
    VECTOR();
}

void INDIVID_PER_LEVEL() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void SPEC_FACTOR_FUNC() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(VIR_TOKEN,VIR_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(VIR_TOKEN,VIR_ERR);
    STAT_FUNCTION();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void CREATE_DATAFRAME() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    COLS();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}


void COLS() {
    COL();
    COLS2();
}

void COLS2() {
    switch (SYM_COUR.CODE)
    {
    case VIR_TOKEN:
        Sym_Suiv();
        COLS();
        break;
    
    default:
        break;
    }
}

void COL() {
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(EG_TOKEN,EG_ERR);
    COL2();
}

void COL2() {
    switch(SYM_COUR.CODE) {
        case C_TOKEN:
            VECTOR();
        break;
        case ID_TOKEN:
            Sym_Suiv();
        break;
        case TRUE_TOKEN:
        case FALSE_TOKEN:
        case INTEGER_TOKEN:
        case DOUBLE_TOKEN:
        case COMPLEX_TOKEN:
            BASIC_TYPE();
        break;
        default:
        Erreur_aff(VVARBASIC_ERR);
        break;
    }
    
}

void SEQ() {
    switch(SYM_COUR.CODE) {
        case SEQ_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            SEQPARAM();
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;

        case REP_TOKEN:
            Sym_Suiv();
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
            Test_Symbole(VIR_TOKEN,VIR_ERR);
            Test_Symbole(PARF_TOKEN,PARF_ERR);
            break;

        case SEQUENCE_TOKEN:
            Sym_Suiv();
            Test_Symbole(C_TOKEN,C_ERR);
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            CN();
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
    }
}

void SEQPARAM() {
    switch(SYM_COUR.CODE) {
        case LENGTH_TOKEN:
        case FROM_TOKEN:
        case TO_TOKEN:
            Sym_Suiv();
            Test_Symbole(EG_TOKEN,EG_ERR);
            Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
            break;
        case LABEL_TOKEN:
            Sym_Suiv();
            Test_Symbole(C_TOKEN,C_ERR);
            Test_Symbole(PARO_TOKEN,PARO_ERR);
            CS();
            Test_Symbole(PARF_TOKEN,PARF_ERR);
        break;
        default:   
        Erreur_aff(PARAM_ERR);
        break;
    }
}

void RSEQ() {
    Sym_Suiv();
    switch (SYM_COUR.CODE)
    {
    case SCALE_TOKEN:
    case LOCATION_TOKEN:
    case MEAN_TOKEN:
    case RATE_TOKEN:
        Sym_Suiv();
        Test_Symbole(EG_TOKEN,EG_ERR);
        Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);
        break;
    
    default:
    Erreur_aff(PARAM_ERR);
        break;
    }
}

void CREATE_LIST() {
    Sym_Suiv();
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    COLS();
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

int main(int argc, char const *argv[])
{
    //argv[1]
    Ouvrir_Fichier("file.r");
    Lire_Car();

  /*  while(!feof(file)){
        INSTRS();
        S();
    }*/
    Sym_Suiv();
     /*   S();
    INSTRS();*/

    SS();
    fclose(file);
    //getchar();
    printf("sssssssssfffffffffffffffffffrrrrrrrrrrBravo !!\n");
    
    return 0;
}



