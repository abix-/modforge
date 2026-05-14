// Address: 0x1401aa9d0
// Ghidra name: FUN_1401aa9d0
// ============ 0x1401aa9d0 FUN_1401aa9d0 (size=203) ============


void FUN_1401aa9d0(undefined8 param_1,int param_2,char param_3)



{

  char cVar1;

  longlong lVar2;

  

  cVar1 = FUN_140163c40(&DAT_1403fcd98);

  if (cVar1 != '\0') {

    lVar2 = FUN_1401aaee0(0,1,&LAB_1401aa980,&LAB_1401aa9c0,0,0);

    DAT_1403fcdb0 = lVar2;

    FUN_140163ab0(&DAT_1403fcd98,lVar2 != 0);

    if (lVar2 == 0) {

      return;

    }

    FUN_1401427d0("SDL_INVALID_PARAM_CHECKS",&LAB_1401aa990,0);

  }

  if (param_3 == '\0') {

    FUN_1401ab340(DAT_1403fcdb0,param_1);

    return;

  }

  FUN_1401ab100(DAT_1403fcdb0,param_1,(longlong)param_2,1);

  return;

}




