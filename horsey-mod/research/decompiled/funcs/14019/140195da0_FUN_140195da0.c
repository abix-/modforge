// Address: 0x140195da0
// Ghidra name: FUN_140195da0
// ============ 0x140195da0 FUN_140195da0 (size=97) ============


undefined4 FUN_140195da0(undefined8 param_1,undefined8 param_2)



{

  undefined4 uVar1;

  longlong lVar2;

  longlong lVar3;

  longlong local_res18 [2];

  

  lVar2 = FUN_14012ffb0();

  if (lVar2 != 0) {

    lVar3 = FUN_14012fd40(param_2);

    lVar2 = lVar2 + lVar3 * 2;

    uVar1 = FUN_14012ffe0(lVar2,local_res18,0x10);

    if (local_res18[0] == lVar2) {

      uVar1 = 0xffffffff;

    }

    return uVar1;

  }

  return 0xffffffff;

}




