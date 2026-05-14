// Address: 0x14015b440
// Ghidra name: FUN_14015b440
// ============ 0x14015b440 FUN_14015b440 (size=243) ============


undefined8 FUN_14015b440(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  undefined4 local_res8 [2];

  longlong local_res18;

  

  iVar2 = FUN_140158700(param_1);

  if (param_1 < DAT_1403fc06c) {

    lVar5 = DAT_1403fc078;

    if ((-1 < param_1) && (*(int *)(DAT_1403fc078 + (longlong)param_1 * 4) == param_2)) {

      return 1;

    }

  }

  else {

    lVar5 = FUN_140184230(DAT_1403fc078,(longlong)(param_1 + 1) << 2);

    if (lVar5 == 0) {

      return 0;

    }

    DAT_1403fc078 = lVar5;

    FUN_1402f94c0(lVar5 + (longlong)DAT_1403fc06c * 4,0,

                  (longlong)((param_1 - DAT_1403fc06c) + 1) << 2);

    DAT_1403fc06c = param_1 + 1;

  }

  iVar3 = FUN_1401591d0(param_2);

  if (-1 < iVar3) {

    *(undefined4 *)(lVar5 + (longlong)iVar3 * 4) = 0;

  }

  if (-1 < param_1) {

    *(int *)(lVar5 + (longlong)param_1 * 4) = param_2;

  }

  cVar1 = FUN_140157a10(param_2,&local_res18,local_res8);

  if (cVar1 != '\0') {

    (**(code **)(local_res18 + 0x40))(local_res8[0],param_1);

  }

  if (iVar2 != 0) {

    uVar4 = FUN_140157960();

    FUN_14015b440(uVar4,iVar2);

  }

  return 1;

}




