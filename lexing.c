#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 

typedef enum {
<<<<<<< HEAD
    NOTA_TOKEN,PRINT_TOKEN,GETWD_TOKEN,SETWD_TOKEN,SCAN_TOKEN,LOG_TOKEN,MAX_TOKEN,MIN_TOKEN,ROUND_TOKEN,SIGNIF_TOKEN,COR_TOKEN,EXP_TOKEN,
=======
<<<<<<< HEAD
    NOTA_TOKEN,PRINT_TOKEN,GETWD_TOKEN,SETWD_TOKEN,SCAN_TOKEN,LOG_TOKEN,MAX_TOKEN,MIN_TOKEN,ROUND_TOKEN,SIGNIF_TOKEN,COR_TOKEN,EXP_TOKEN,
=======
    PRINT_TOKEN,GETWD_TOKEN,SETWD_TOKEN,SCAN_TOKEN,LOG_TOKEN,MAX_TOKEN,MIN_TOKEN,ROUND_TOKEN,SIGNIF_TOKEN,COR_TOKEN,EXP_TOKEN,
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    C_TOKEN,SORT_TOKEN,REV_TOKEN,UNIQUE_TOKEN,TABLE_TOKEN,AS_TOKEN,IF_TOKEN,ELSE_TOKEN,WHILE_TOKEN,REPEAT_TOKEN,FOR_TOKEN,
    SWITCH_TOKEN,BREAK_TOKEN,NEXT_TOKEN,FUNCTION_TOKEN,BODY_TOKEN,INPUT_TOKEN,END_TOKEN,OF_TOKEN,TYPEOF_TOKEN,
    LIST_TOKEN,DATAFRAME_TOKEN,ATTR_TOKEN,CHARACTER_TOKEN,ATOMIC_TOKEN,
    VECTOR_TOKEN,AS_NUMERIC_TOKEN,AS_DOUBLE_TOKEN,AS_INTEGER_TOKEN,AS_CHARACTER_TOKEN,IS_LOGICAL_TOKEN,IS_INTEGER_TOKEN,
    IS_DOUBLE_TOKEN,IS_CHARACTER_TOKEN,IS_ATOMIC_TOKEN,IS_VECTOR_TOKEN,IS_NUMERIC_TOKEN,TRUE_TOKEN,FALSE_TOKEN,
    LENGTH_TOKEN,PI_TOKEN,LETTERS_TOKEN,LS_TOKEN,PAT_TOKEN,LS_STR_TOKEN,MAX_LEVEL_TOKEN,EPS_TOKEN,MONTH_NAME_TOKEN,MONTH_ABB_TOKEN,
    NULL_TOKEN,RM_TOKEN,HELP_TOKEN,MODE_TOKEN,CAT_TOKEN,SEP_TOKEN,QUOTE_TOKEN,HEADER_TOKEN,DEC_TOKEN,READ_CSV_TOKEN,READ_CSV2_TOKEN,
    READ_DELIM_TOKEN,READ_DELIM2_TOKEN,READ_TABLE_TOKEN,ROW_NAMES_TOKEN,COL_NAMES_TOKEN,FILE_TOKEN,SEQ_TOKEN,FROM_TOKEN,REP_TOKEN,
    SEQUENCE_TOKEN,TO_TOKEN,GL_TOKEN,LABEL_TOKEN,RNORM_TOKEN,DNORM_TOKEN,PNORM_TOKEN,QNORM_TOKEN,REXP_TOKEN,DEXP_TOKEN,
    PEXP_TOKEN,QEXP_TOKEN,RGAMMA_TOKEN,DGAMMA_TOKEN,PGAMMA_TOKEN,QGAMMA_TOKEN,RNBINOM_TOKEN,DNBINOM_TOKEN,PNBINOM_TOKEN,QNBINOM_TOKEN,
    RUNIF_TOKEN,DUNIF_TOKEN,PUNIF_TOKEN,QUNIF_TOKEN,RGEOM_TOKEN,DGEOM_TOKEN,PGEOM_TOKEN,QGEOM_TOKEN,RCAUCHY_TOKEN,DCAUCHY_TOKEN,
    PCAUCHY_TOKEN,QCAUCHY_TOKEN,RPOIS_TOKEN,DPOIS_TOKEN,PPOIS_TOKEN,QPOIS_TOKEN,RF_TOKEN,DF_TOKEN,PF_TOKEN,QF_TOKEN,RT_TOKEN,DT_TOKEN,
    PT_TOKEN,QT_TOKEN,RLOGIS_TOKEN,DLOGIS_TOKEN,PLOGIS_TOKEN,QLOGIS_TOKEN,SCALE_TOKEN,LOCATION_TOKEN,MEAN_TOKEN,RATE_TOKEN,FACTOR_TOKEN,
    LEVEL_TOKEN,LABELS_TOKEN,EXCLUDE_TOKEN,

    LOG2_TOKEN,LOG10_TOKEN,COS_TOKEN,SIN_TOKEN,TAN_TOKEN,ACOS_TOKEN,ASIN_TOKEN,ATAN_TOKEN,ABS_TOKEN,SQRT_TOKEN,RANGE_TOKEN,SUM_TOKEN,
<<<<<<< HEAD
    PROD_TOKEN,SD_TOKEN,VAR_TOKEN,IS_COMPLEX_TOKEN,AS_LOGICAL_TOKEN,IS_NA_TOKEN,IS_NAN_TOKEN,NAMES_TOKEN,RBIND_TOKEN,CBIND_TOKEN,
=======
<<<<<<< HEAD
    PROD_TOKEN,SD_TOKEN,VAR_TOKEN,IS_COMPLEX_TOKEN,AS_LOGICAL_TOKEN,IS_NA_TOKEN,IS_NAN_TOKEN,NAMES_TOKEN,RBIND_TOKEN,CBIND_TOKEN,
=======
    PROD_TOKEN,SD_TOKEN,VAR_TOKEN,IS_COMPLEXE_TOKEN,AS_LOGICAL_TOKEN,IS_NA_TOKEN,IS_NAN_TOKEN,NAMES_TOKEN,RBIND_TOKEN,CBIND_TOKEN,
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    MATRIX_TOKEN,DATA_TOKEN,NROW_TOKEN,NCOL_TOKEN,BYROW_TOKEN,DIMNAMES_TOKEN,T_TOKEN,DIM_TOKEN,ROWSUMS_TOKEN,COLSUMS_TOKEN,
    COLMEANS_TOKEN,ROWMEANS_TOKEN,APPLY_TOKEN,LEVELS_TOKEN,IS_FACTOR_TOKEN,AS_FACTOR_TOKEN,SUMMARY_TOKEN,TAPPLY_TOKEN,
    IS_DATA_FRAME_TOKEN,AS_DATA_FRAME_TOKEN,SUBSET_TOKEN,ATTACH_TOKEN,DETACH_TOKEN,FILE_CHOOSE_TOKEN,READ_TSV_TOKEN,WRITE_TABLE_TOKEN,
    WRITE_CSV_TOKEN,WRITE_CSV2_TOKEN,SAVERDS_TOKEN,READRDS_TOKEN,LOAD_TOKEN,SAVE_TOKEN,SAVE_IMAGE_TOKEN,NA_TOKEN,CLASS_TOKEN,


    PV_TOKEN,PARO_TOKEN,PARF_TOKEN,MINUS_TOKEN,PLS_TOKEN,MULT_TOKEN,DIV_TOKEN,NEG_TOKEN,
    TILD_TOKEN,DP_TOKEN,INTER_TOKEN,POWER_TOKEN,INF_TOKEN,SUP_TOKEN,EG_TOKEN,EQ_TOKEN,DIFF_TOKEN,INFEG_TOKEN,SUPEG_TOKEN,DET_TOKEN,
<<<<<<< HEAD
    ET_TOKEN,OU_TOKEN,DOU_TOKEN,AFFTOD_TOKEN,AFFTOG_TOKEN,VIR_TOKEN,DOLLAR_TOKEN,IN_TOKEN,MOD_TOKEN,
=======
<<<<<<< HEAD
    ET_TOKEN,OU_TOKEN,DOU_TOKEN,AFFTOD_TOKEN,AFFTOG_TOKEN,VIR_TOKEN,DOLLAR_TOKEN,IN_TOKEN,MOD_TOKEN,
=======
    ET_TOKEN,OU_TOKEN,DOU_TOKEN,AFFTOD_TOKEN,AFFTOG_TOKEN,VIR_TOKEN,DOLLAR_TOKEN,IN_TOKEN,MOD_TOKEN,DQ_TOKEN,SQ_TOKEN,
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    ACCO_TOKEN,ACCF_TOKEN,BRO_TOKEN,BRF_TOKEN,SEPARATEUR_TOKEN,
    
    INTEGER_TOKEN,DOUBLE_TOKEN,LOGICAL_TOKEN,STRING_TOKEN,NEWLINE_TOKEN,
    
<<<<<<< HEAD
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEX_TOKEN,CHAINE_TOKEN
=======
<<<<<<< HEAD
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEX_TOKEN,CHAINE_TOKEN
=======
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEXE_TOKEN,CHAINE_TOKEN
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8

}CODES_LEX;

typedef struct {
    char TOKEN_NAME[40];
    CODES_LEX CODE;
}TOKEN;

<<<<<<< HEAD
int NUMBEROFTOKENS = 238;
=======
<<<<<<< HEAD
int NUMBEROFTOKENS = 238;
=======
int NUMBEROFTOKENS = 240;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8

int DEBUTMOTCLE = 0;
int FINMOTCLE = 194;

TOKEN ALLTOKENS[231] = {
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
    {"row.names",ROW_NAMES_TOKEN},
    {"col.names",COL_NAMES_TOKEN},
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
<<<<<<< HEAD
    {"is.complex",IS_COMPLEX_TOKEN},
=======
<<<<<<< HEAD
    {"is.complex",IS_COMPLEX_TOKEN},
=======
    {"is.complexe",IS_COMPLEXE_TOKEN},
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    {"\"",DQ_TOKEN},
    {"'",SQ_TOKEN},
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    {"{",ACCO_TOKEN},
    {"}",ACCF_TOKEN},
    {"[",BRO_TOKEN},
    {"]",BRF_TOKEN},
    {"#",COM_TOKEN}
};

typedef struct {
    char TOKEN_TEXT[40];
    CODES_LEX CODE;
}TOKEN_TEXT;

<<<<<<< HEAD
TOKEN_TEXT ALLTOKENS_TEXT[238] = {
=======
<<<<<<< HEAD
TOKEN_TEXT ALLTOKENS_TEXT[238] = {
=======
TOKEN_TEXT ALLTOKENS_TEXT[240] = {
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
    {"ROW_NAMES_TOKEN",ROW_NAMES_TOKEN},
    {"COL_NAMES_TOKEN",COL_NAMES_TOKEN},
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
<<<<<<< HEAD
    {"IS_COMPLEX_TOKEN",IS_COMPLEX_TOKEN},
=======
<<<<<<< HEAD
    {"IS_COMPLEX_TOKEN",IS_COMPLEX_TOKEN},
=======
    {"IS_COMPLEXE_TOKEN",IS_COMPLEXE_TOKEN},
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    {"DQ_TOKEN",DQ_TOKEN},
    {"SQ_TOKEN",SQ_TOKEN},
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
    {"COMPLEX_TOKEN",COMPLEX_TOKEN},
=======
<<<<<<< HEAD
    {"COMPLEX_TOKEN",COMPLEX_TOKEN},
=======
    {"COMPLEXE_TOKEN",COMPLEXE_TOKEN},
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    {"CHAINE_TOKEN",CHAINE_TOKEN}
};

typedef struct {
    CODES_LEX CODE;
    char NOM[101];
}TSym_Cour;

// Variable Globale
int MAX_ID_NAME_LENGTH = 100;
char Car_Cour;
FILE *file;
TSym_Cour SYM_COUR;
int Ligne_Courante = 1;
int Colonne_Courante = 0;
char NOM[101];
int Length_NOM = 0;


//Prototypes
void Vider_NOM();
void Ouvrir_Fichier(const char path[]);
void Lire_Car();
bool Separateur();
void Sym_Suiv();
void AfficherToken(TSym_Cour SYM);
CODES_LEX code_mot_cle(char nom[]);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
bool mot_cle(char nom[]);
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
void lire_mot();
void lire_special();
void lire_commentaire();
void lire_nombre();
int isalpha();
int isdigit();
void lire_chaine();
void lire_separateur();


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
    } else {
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
<<<<<<< HEAD
        else if(Car_Cour ==  '\"' || Car_Cour == 39){ lire_chaine(); }
=======
<<<<<<< HEAD
        else if(Car_Cour ==  '\"' || Car_Cour == 39){ lire_chaine(); }
=======
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
        else { lire_special(); }
}

void AfficherToken(TSym_Cour SYM){
    if( SYM.CODE == ERREUR_TOKEN) {
        printf("erreur ligne %d colonne %d .\n", Ligne_Courante, Colonne_Courante);
        exit(EXIT_FAILURE);
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
<<<<<<< HEAD
    return NOTA_TOKEN;
=======
<<<<<<< HEAD
    return NOTA_TOKEN;
=======
}

bool mot_cle(char nom[]){
    for(int i=DEBUTMOTCLE ; i <= FINMOTCLE ; i++){
        if( strcmp(nom,ALLTOKENS[i].TOKEN_NAME) == 0 ){
            return true;
        }
    }
    return false;
    
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
            if(code_mot_cle(NOM)!=NOTA_TOKEN){
=======
<<<<<<< HEAD
            if(code_mot_cle(NOM)!=NOTA_TOKEN){
=======
            if(mot_cle(NOM)){
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    case '\"':
        SYM_COUR.CODE = DQ_TOKEN;
        AfficherToken(SYM_COUR);
        lire_chaine();
        break;
    case 39:
        SYM_COUR.CODE = SQ_TOKEN;
        AfficherToken(SYM_COUR);
        lire_chaine();
        break;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
    AfficherToken(SYM_COUR);
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    Lire_Car();
    while( !feof(file) && (Length_NOM <= 100) ) {
        if( Car_Cour == simpleORdouble && (NOM[Length_NOM-1] != 92) ) {
            isClosedQuotes = true;
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
            SYM_COUR.CODE = simpleORdouble == '\"' ? DQ_TOKEN : SQ_TOKEN;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
                        SYM_COUR.CODE = COMPLEX_TOKEN;
=======
<<<<<<< HEAD
                        SYM_COUR.CODE = COMPLEX_TOKEN;
=======
                        SYM_COUR.CODE = COMPLEXE_TOKEN;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
<<<<<<< HEAD
                    SYM_COUR.CODE = COMPLEX_TOKEN;
=======
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
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

<<<<<<< HEAD
int main(int argc, char const *argv[]) {
=======
<<<<<<< HEAD
int main(int argc, char const *argv[]) {
=======
int main(int argc, char const *argv[])
{
>>>>>>> f9d0fc95796ba74b3c0377cca68916433a1108a7
>>>>>>> ec28abc5a6b4a1cbf049f3ef939742ebff0426f8
    //argv[1]
    Ouvrir_Fichier("file.r");
    Lire_Car();

    while(Car_Cour != EOF){
        Sym_Suiv();
        AfficherToken(SYM_COUR);
    }
    if(Car_Cour == EOF) {
        printf("FIN_TOKEN\n");
        exit(EXIT_SUCCESS);
    }
    fclose(file);
    getchar();
    
    //printf("%s\n",ALLTOKENS[FINMOTCLE].TOKEN_NAME);
    
    return 0;
}