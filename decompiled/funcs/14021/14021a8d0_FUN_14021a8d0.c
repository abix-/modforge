// Address: 0x14021a8d0
// Ghidra name: FUN_14021a8d0
// ============ 0x14021a8d0 FUN_14021a8d0 (size=206) ============


undefined8

FUN_14021a8d0(undefined4 param_1,undefined8 param_2,code *param_3,undefined8 param_4,

             undefined8 param_5,undefined8 param_6)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  DAT_1403fdb30 = param_5;

  DAT_1403fdb40 = param_6;

  DAT_1403fdb38 = param_4;

  FUN_140139010(&DAT_1403fdb48,0);

  iVar2 = (*param_3)(&DAT_1403fdb50,param_1,param_2);

  cVar1 = FUN_140138fc0(&DAT_1403fdb48,0,iVar2);

  if ((cVar1 != '\0') && (iVar2 == 0)) {

    cVar1 = FUN_14017e460(0x4000);

    if (cVar1 != '\0') {

      cVar1 = FUN_1401391a0(FUN_14021aa10,0);

      if (cVar1 != '\0') goto LAB_14021a983;

    }

    FUN_140139010(&DAT_1403fdb48,2);

    return 2;

  }

LAB_14021a983:

  uVar3 = FUN_140138fe0(&DAT_1403fdb48);

  return uVar3;

}




