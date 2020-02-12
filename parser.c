#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 

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
    
    COM_TOKEN,ID_TOKEN,FIN_TOKEN,ERREUR_TOKEN,COMPLEX_TOKEN

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
    

}Erreurs;

int NOMBRE_ERREUR = 42;

typedef struct {
    Erreurs CODE_ERR;
    char MES[40];
}Erreur;

Erreur MES_ERR[42] = {
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
    {NLSNA_ERR, "Numeric Logical String or NA Manquant"}
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
        else if(Car_Cour ==  '\"' || Car_Cour == 39){ lire_chaine(); }
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

void Test_Symbole(CODES_LEX CODE_LEX,Erreurs CODE_ERR) {
    if(SYM_COUR.CODE == CODE_LEX) {
        Sym_Suiv();
    }
    else {
        Erreur_aff(CODE_ERR);
    }
}

void S() {
    Sym_Suiv();
    switch (SYM_COUR.CODE) {
        case INTER_TOKEN:
            INTERHELP();
        break;
        case HELP_TOKEN:
            HELP();
        break;
        case PRINT_TOKEN:
            PRINT();
        break;
        case LEVELS_TOKEN:
            LEVELS();
            AEXP1();
        break;

        case LS_TOKEN:
            LIST();
        break;

        case SUBSET_TOKEN:
        case ATTACH_TOKEN:
        case DETACH_TOKEN:
            SUBSET_DATAFRAME();
            AEXP2();
        break;
        
        case RM_TOKEN:
            REMOVE();
        break;

        case NAMES_TOKEN:
            ELEMENT_NAMES();
        break;

        case ROWNAMES_TOKEN:
        case COLNAMES_TOKEN:
            A();
        break;
        
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
            EXP();
        break;


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
        default:
            Erreur_aff(ID_ERR);
        break;
    }
}

/*void Vprime() {
    switch(SYM_COUR.CODE) {
        case AFFTOG_TOKEN:
        case EG_TOKEN:
            ASSIGN();
            EXP();
        break;
        case DOLLAR_TOKEN:
        case 
    }

}*/

int main(int argc, char const *argv[])
{
    //argv[1]
    Ouvrir_Fichier("file.r");
    Lire_Car();

    
    S();
    
    fclose(file);
    getchar();
    printf("Bravo !!\n");
    //printf("%s\n",ALLTOKENS[FINMOTCLE].TOKEN_NAME);
    
    return 0;
}



