// Address: 0x140228760
// Ghidra name: FUN_140228760
// ============ 0x140228760 FUN_140228760 (size=514) ============


byte FUN_140228760(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  int iVar6;

  longlong lVar7;

  longlong lVar8;

  longlong lVar9;

  longlong lVar10;

  longlong lVar11;

  undefined8 uVar12;

  byte extraout_var;

  byte extraout_var_00;

  undefined4 local_res10;

  undefined2 local_res14;

  undefined4 local_res18;

  int local_48;

  

  local_res18 = param_3;

  lVar7 = FUN_140146900(param_2,param_5);

  if (lVar7 == 0) {

    return 0;

  }

  bVar2 = FUN_14012cd80(param_1,0x6e6f6369);

  lVar8 = FUN_14012cba0(param_1);

  bVar3 = FUN_14012cd80(param_1,0);

  local_res10 = 0x20000;

  local_48 = (int)lVar8 + 4;

  local_res14 = 1;

  lVar9 = FUN_14012cbb0(param_1,&local_res10,6);

  lVar10 = FUN_1401841f0(0x10);

  if (lVar10 == 0) {

    bVar2 = 0;

  }

  else {

    lVar11 = FUN_14012cbb0(param_1,lVar10,0x10);

    bVar1 = 0;

    if (lVar11 == 0x10) {

      bVar1 = lVar9 == 6 & bVar3 & bVar2;

    }

    iVar6 = FUN_14012cba0(param_1);

    bVar3 = FUN_140228970(param_1,lVar7);

    uVar12 = FUN_14012cba0(param_1);

    bVar4 = FUN_140227530(lVar10,lVar7,local_res18,param_4,(int)uVar12 - iVar6,iVar6 - local_48);

    FUN_14012cb40(param_1,lVar8 + 10,0);

    lVar9 = FUN_14012cbb0(param_1,lVar10,0x10);

    FUN_14012cb40(param_1,uVar12,0);

    FUN_1401841e0(lVar10);

    bVar5 = FUN_1402278c0(param_1,lVar8);

    bVar2 = 0;

    if (lVar9 == 0x10) {

      bVar2 = (extraout_var_00 >> 7 ^ 1) & (extraout_var >> 7 ^ 1);

    }

    bVar2 = bVar5 & bVar2 & bVar4 & bVar3 & bVar1;

  }

  FUN_140146010(lVar7);

  return bVar2;

}




