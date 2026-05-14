// Address: 0x1401699c0
// Ghidra name: FUN_1401699c0
// ============ 0x1401699c0 FUN_1401699c0 (size=126) ============


void FUN_1401699c0(char *param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  undefined8 local_res10 [3];

  

  lVar1 = FUN_14016dcf0();

  if (lVar1 == 0) {

    FUN_1401730c0();

    return;

  }

  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {

    uVar2 = FUN_1401694d0(lVar1,local_res10);

    uVar3 = FUN_14012f0d0(param_1);

    FUN_1401697e0(FUN_140169040,FUN_1401841e0,uVar3,uVar2,local_res10[0]);

    return;

  }

  FUN_140169010();

  return;

}




