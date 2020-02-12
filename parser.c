#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 


//Enumeration

typedef enum {
    PRINT_TOKEN,GETWD_TOKEN,SETWD_TOKEN,SCAN_TOKEN,LOG_TOKEN,MAX_TOKEN,MIN_TOKEN,ROUND_TOKEN,SIGNIF_TOKEN,COR_TOKEN,EXP_TOKEN,
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
    
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEXE_TOKEN,CHAINE_TOKEN,NUM_TOKEN

}CODES_LEX;

typedef enum {
    ERR_CAR_INC,ERR_FICH_VIDE,ERR_ID_LONG,ERR_NUM_LONG,ID_INV,ERR_FICH_INEX,
    VAR_ERR, DQ_ERR, SQ_ERR, STRING_ERR, HELP_ERR,INTER_ERR, PARO_ERR, PARF_ERR, DQANDSQ_ERR, PRINT_ERR, ID_ERR, AFFTOG_ERR,AFFTOD_ERR,
    EQ_ERR,  AFFECTATION_ERR, NUM_ERR, EG_ERR, MODE_ERR, CAT_ERR, LENGTH_ERR, LOG10_ERR, LOG2_ERR, EXP_ERR, COS_ERR, SIN_ERR, TANG_ERR,
    ACOS_ERR, ASIN_ERR, ATANG_ERR, ABS_ERR,SQRT_ERR, DOUBLE_ERR, INTEGER_ERR, C_ERR, TRUE_ERR, FALSE_ERR
}Erreurs;

typedef struct {
    char TOKEN_NAME[40];
    CODES_LEX CODE;
}TOKEN;

typedef struct {
    char TOKEN_TEXT[40];
    CODES_LEX CODE;
}TOKEN_TEXT;

typedef struct {
    Erreurs CODE_ERR;
    char MES[40];
}Erreur;

typedef struct {
    CODES_LEX CODE;
    char NOM[101];
}TSym_Cour;

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

TOKEN_TEXT ALLTOKENS_TEXT[240] = {
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
    {"COMPLEXE_TOKEN",COMPLEXE_TOKEN},
    {"CHAINE_TOKEN",CHAINE_TOKEN},
    
};

int NOMBRE_ERREUR = 200;

Erreur MES_ERR[100] = {
    {ERR_CAR_INC , "Caractere inconnu"},
    {ERR_FICH_VIDE , "Fichier Vide"},
    {ERR_ID_LONG , "IDF Long"},
    {ERR_NUM_LONG , "Numero Long"},
    {ID_INV , "ID Invalid"},
    {ERR_FICH_INEX , "Fichier inexistant"},
    {VAR_ERR , "Var Erreur"},
    {DQ_ERR , "Double quate erreur"},
    {SQ_ERR , "Simple quote erreur"},
    {STRING_ERR , "String erreur"},
    {HELP_ERR , "Erreur dans la syntaxe de help()"},
    {INTER_ERR , "Manque ?"},
    {PARO_ERR , "Mansque ("},
    {PARF_ERR , "Manque )"},
    {DQANDSQ_ERR , "Erreur, Manque \" ou \' "},
    {PRINT_ERR , "Erreur dans la syntaxe de print()"},
    {ID_ERR , "ID Erreur"},
    {AFFTOG_ERR , "<- Erreur"},
    {AFFTOD_ERR , "-> Erreur"},
    {EQ_ERR, "= Erreur"},
    {AFFECTATION_ERR, "Erreur dans l'affectation"},
    {NUM_ERR, "Number Erreur "},
    {EG_ERR, "Egalité Erreur "},
    {MODE_ERR, "Mode  fonction Erreur "},
    {CAT_ERR, "Cat fonction  Erreur "},
    {LENGTH_ERR, "Length fonction Erreur "},
    {LOG10_ERR, "Log10 fonction Erreur "},
    {LOG2_ERR, "Log2 fonction Erreur "},
    {EXP_ERR, "Exponentiel fonction Erreur "},
    {COS_ERR, "Cosinus fonction Erreur "},
    {SIN_ERR, "Sinus fonction Erreur "},
    {TANG_ERR, "Tangent fonction Erreur "},
    {ACOS_ERR, "Acosinus fonction Erreur "},
    {ASIN_ERR, "Asinus fonction Erreur "},
    {ATANG_ERR, "Atangent fonction Erreur "},
    {ABS_ERR, "Abs fonction Erreur "},
    {SQRT_ERR, "sqrt fonction Erreur "},
    {DOUBLE_ERR, "Double Erreur "},
    {INTEGER_ERR, "Integer  Erreur "},
    {C_ERR, "Vecteur c Erreur "},
    {TRUE_ERR, "TRUE c Erreur "},
    {FALSE_ERR, "False c Erreur "}
    
    };

// Variable Globale
int MAX_ID_NAME_LENGTH = 100;
char Car_Cour;
FILE *file;
TSym_Cour SYM_COUR;
int Ligne_Courante = 1;
int Colonne_Courante = 0;
char NOM[101];
int Length_NOM = 0;
Erreurs CODE_ERR;


//Prototypes
void Vider_NOM();
void Ouvrir_Fichier(const char path[]);
void Lire_Car();
bool Separateur();
void Sym_Suiv();
void AfficherToken(TSym_Cour SYM);
CODES_LEX code_mot_cle(char nom[]);
bool mot_cle(char nom[]);
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
    Car_Cour = fgetc(file);
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
}

bool mot_cle(char nom[]){
    for(int i=DEBUTMOTCLE ; i <= FINMOTCLE ; i++){
        if( strcmp(nom,ALLTOKENS[i].TOKEN_NAME) == 0 ){
            return true;
        }
    }
    return false;
    
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
            if(mot_cle(NOM)){
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
    AfficherToken(SYM_COUR);
    Lire_Car();
    while( !feof(file) && (Length_NOM <= 100) ) {
        // 92 = antislash 
        if( Car_Cour == simpleORdouble && (NOM[Length_NOM-1] != 92) ) {
            isClosedQuotes = true;
            SYM_COUR.CODE = simpleORdouble == '\"' ? DQ_TOKEN : SQ_TOKEN;
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

// **************Boufous********************
/*void lire_chaine() {
    bool isClosedQuotes = false;
    char simpleORdouble = Car_Cour;
    SYM_COUR.CODE = STRING_TOKEN;
    AfficherToken(SYM_COUR);
    Lire_Car();
    while( !feof(file) && (Length_NOM <= 100) ) {
        // 92 = antislash 
        if( Car_Cour == simpleORdouble && (NOM[Length_NOM-1] != 92) ) {
            isClosedQuotes = true;
            SYM_COUR.CODE = simpleORdouble == '\"' ? DQ_TOKEN : SQ_TOKEN;
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
}*/

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
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
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
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
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
                        SYM_COUR.CODE = COMPLEXE_TOKEN;
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
                    SYM_COUR.CODE = COMPLEXE_TOKEN;
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

CODES_LEX dqORsq(CODES_LEX symbole){
    switch(symbole){
        case DQ_TOKEN: return DQ_TOKEN;break;
        case SQ_TOKEN: return SQ_TOKEN;break;
        default: return -1;
    }

}




////////////////////////
//Analyseur Syntaxique
////////////////////////


//prototype
void help();
void interHelp();
void stringArgs();
void print();
void varArgs();
void affSymbole();
void affec();
void expr();
void term();
void fact();
//Fonctions Arithemetique
void mode();
void cat();
void log2_();
void log10_();
void exp_();
void cos_();
void tan_();
void sin_();
void acos_();
void asin_();
void atan_();
void abs_();
void max_();
void min_();
void range();
void length_();
void sum();
void prod();
void mean();
void sd();
void var();
void sort();
void sqrt_();

//Vecteurs, matric, list
void c();
void args();



void Test_Symbole(CODES_LEX CODE_LEX,Erreurs CODE_ERR) {
    if(SYM_COUR.CODE == CODE_LEX) {
        Sym_Suiv();
    }
    else {
        Erreur_aff(CODE_ERR);
    }
}

void S() {
    
    switch (SYM_COUR.CODE) {
        case INTER_TOKEN: interHelp();break;
        case HELP_TOKEN:  help();break;
        case PRINT_TOKEN: print(); break;
        case ROW_NAMES_TOKEN:
        case COL_NAMES_TOKEN:
        case LEVELS_TOKEN:break;
        case LS_TOKEN:break;
        case RM_TOKEN:break;
        case ID_TOKEN: affec();
        case TRUE_TOKEN: break;
        case FALSE_TOKEN: break;
        case INTEGER_TOKEN: break;
        case DOUBLE_TOKEN: break;
        case STRING_TOKEN:break;
        case COMPLEXE_TOKEN:break;
        case C_TOKEN: c();break;
        case MODE_TOKEN: mode();break;
        case CAT_TOKEN: cat();break;
        case LENGTH_TOKEN: length_();break;
        case LOG2_TOKEN: log2_();break;
        case LOG10_TOKEN:log10_();break;
        case EXP_TOKEN: exp_();break;
        case COS_TOKEN: cos_();break;
        case SIN_TOKEN: sin_();break;
        case TAN_TOKEN: tan_();break;
        case ACOS_TOKEN:acos_();break;
        case ASIN_TOKEN: asin_();break;
        case ATAN_TOKEN: atan_();break;
        case ABS_TOKEN: abs_();break;
        case SQRT_TOKEN:sqrt_();break;
        case MAX_TOKEN:
        case MIN_TOKEN:
        case RANGE_TOKEN:
        case SUM_TOKEN:
        case PROD_TOKEN:
        case MEAN_TOKEN:
        case SD_TOKEN:
        case VAR_TOKEN:
        case SORT_TOKEN:break;
        case TYPEOF_TOKEN:
        case CLASS_TOKEN:break;
        case IS_NUMERIC_TOKEN:
        case IS_CHARACTER_TOKEN:
        case IS_LOGICAL_TOKEN:
        case IS_COMPLEX_TOKEN:
        case IS_NA_TOKEN:
        case IS_NAN_TOKEN:
        case IS_FACTOR_TOKEN:
        case IS_DATA_FRAME_TOKEN:break;
        case AS_NUMERIC_TOKEN:
        case AS_CHARACTER_TOKEN:
        case AS_LOGICAL_TOKEN:
        case AS_FACTOR_TOKEN:
        case AS_DATA_FRAME_TOKEN:break;
        case RBIND_TOKEN:
        case CBIND_TOKEN:
        case MATRIX_TOKEN:break;
        case T_TOKEN:break;
        case NCOL_TOKEN:
        case NROW_TOKEN:
        case DIM_TOKEN:break;
        case ROWSUMS_TOKEN:
        case COLSUMS_TOKEN:
        case COLMEANS_TOKEN:
        case ROWMEANS_TOKEN:
        case APPLY_TOKEN:break;
        case FACTOR_TOKEN:break;
        case SUMMARY_TOKEN:break;
        case TAPPLY_TOKEN:
        case TABLE_TOKEN:break;
        case DATAFRAME_TOKEN:
        break;
        
        default:break;
    }
}

void STAT_FUNCTION() {
    switch(SYM_COUR.CODE) {
        case MAX_TOKEN:
        case MIN_TOKEN:
        case RANGE_TOKEN:
        case LENGTH_TOKEN:
        case SUM_TOKEN:
        case PROD_TOKEN:
        case MEAN_TOKEN:
        case SD_TOKEN:
        case VAR_TOKEN:
        case SORT_TOKEN:
        Sym_Suiv();
        Test_Symbole(PARO_TOKEN,PARO_TOKEN);
        Test_Symbole(PARF_TOKEN,PARF_TOKEN);
        default: break;

    }
}

//  Help => EX: ?print
void interHelp(){
    Test_Symbole(INTER_TOKEN,INTER_ERR);
    Test_Symbole(STRING_TOKEN,STRING_ERR);
} 
//Help => EX: help("print") , ca peut avoir pleusieur arguments (parametres)
void help(){
    Test_Symbole(HELP_TOKEN,HELP_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    stringArgs();
    }

//fonction tres util!! s'applique dans tous les fonction d'arguments de type string
void stringArgs(){
    Test_Symbole(STRING_TOKEN,STRING_ERR);
    while(SYM_COUR.CODE == VIR_TOKEN){
        Sym_Suiv();
        Test_Symbole(STRING_TOKEN,STRING_ERR);
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    
}



void print(){
    Test_Symbole(PRINT_TOKEN,PRINT_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    varArgs();

}

//fonction tres util!! s'applique dans tous les fonction d'arguments de type string
void varArgs(){
    Test_Symbole(ID_TOKEN,ID_ERR);
    while(SYM_COUR.CODE == VIR_TOKEN){
        Sym_Suiv();
        Test_Symbole(ID_TOKEN,ID_ERR);
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
    
}

// AFFECTATION les cas traiter:  =  <-
void affec(){
    Test_Symbole(ID_TOKEN,ID_ERR);
    switch(SYM_COUR.CODE){
        case AFFTOG_TOKEN: Test_Symbole(AFFTOG_TOKEN,AFFTOG_ERR);
                           expr(); break;
        case EG_TOKEN : Test_Symbole(EG_TOKEN,EG_ERR);
                        expr();break;

        default: Erreur_aff(AFFECTATION_ERR); break;
    }
}

void expr(){
    term();
    while(SYM_COUR.CODE == PLS_TOKEN || SYM_COUR.CODE == MINUS_TOKEN){
        Sym_Suiv();
        term();
    }

}
void term(){
    fact();
    while(SYM_COUR.CODE == MULT_TOKEN || SYM_COUR.CODE == DIV_TOKEN){
        Sym_Suiv();
        fact();
    }

}

void fact(){
    switch(SYM_COUR.CODE){
        case ID_TOKEN: Test_Symbole(ID_TOKEN,ID_ERR);break;
        case NUM_TOKEN: Test_Symbole(NUM_TOKEN,NUM_ERR);break;
        default:Erreur_aff(AFFECTATION_ERR); break;
    }
}

void mode(){
    Test_Symbole(MODE_TOKEN,MODE_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void cat(){
    Test_Symbole(CAT_TOKEN,CAT_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}


void length_(){
    Test_Symbole(LENGTH_TOKEN,LENGTH_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    Test_Symbole(ID_TOKEN,ID_ERR);
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}


void log10_(){
    Test_Symbole(LOG10_TOKEN,LOG10_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(LOG10_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void log2_(){
    Test_Symbole(LOG2_TOKEN,LOG2_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(LOG2_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void exp_(){
    Test_Symbole(EXP_TOKEN,EXP_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(EXP_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void sin_(){
    Test_Symbole(SIN_TOKEN,SIN_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(SIN_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void tan_(){
    Test_Symbole(TAN_TOKEN,TANG_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(SIN_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}
void cos_(){
    Test_Symbole(COS_TOKEN,COS_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(COS_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}
void acos_(){
    Test_Symbole(ACOS_TOKEN,ACOS_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(ACOS_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}
void asin_(){
    Test_Symbole(ASIN_TOKEN,ASIN_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(ASIN_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}
void atan_(){
    Test_Symbole(ATAN_TOKEN,ATANG_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(ATANG_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void abs_(){
    Test_Symbole(ABS_TOKEN,ABS_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(ABS_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void sqrt_(){
    Test_Symbole(SQRT_TOKEN,SQRT_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(SQRT_ERR);break;
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void max_(){

}


void c(){
    Test_Symbole(C_TOKEN,C_ERR);
    Test_Symbole(PARO_TOKEN,PARO_ERR);
    printf("%s\n",ALLTOKENS_TEXT[SYM_COUR.CODE].TOKEN_TEXT);
    args();
    while(SYM_COUR.CODE == VIR_TOKEN){
        Sym_Suiv();
        args();
    }
    Test_Symbole(PARF_TOKEN,PARF_ERR);
}

void args(){
    switch(SYM_COUR.CODE){
        case STRING_TOKEN: Test_Symbole(STRING_TOKEN,STRING_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,DOUBLE_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        case TRUE_TOKEN: Test_Symbole(TRUE_TOKEN,TRUE_ERR);break;
        case FALSE_TOKEN: Test_Symbole(FALSE_TOKEN,FALSE_ERR);break;
        default: Erreur_aff(C_ERR);break;
    }
}












int main(int argc, char const *argv[])
{
    //argv[1]
    Ouvrir_Fichier("test_syntaxique.r");
    Sym_Suiv();
    S();
    /*while(Car_Cour != EOF){
        Sym_Suiv();
        AfficherToken(SYM_COUR);
    }
    if(Car_Cour == EOF) {
        printf("FIN_TOKEN\n");
        exit(EXIT_SUCCESS);
    }*/


    printf("Bravo!!!!"); 
    fclose(file);
    getchar();
    
    //printf("%s\n",ALLTOKENS[FINMOTCLE].TOKEN_NAME);
    
    return 0;
}



