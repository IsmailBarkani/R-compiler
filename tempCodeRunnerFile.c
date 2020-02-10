switch(SYM_COUR.CODE){
        case ID_TOKEN:Test_Symbole(ID_TOKEN,ID_ERR);break;
        case DOUBLE_TOKEN: Test_Symbole(DOUBLE_TOKEN,INTEGER_ERR);break;
        case INTEGER_TOKEN: Test_Symbole(INTEGER_TOKEN,INTEGER_ERR);break;
        default: Erreur_aff(LOG10_ERR);break;
    }