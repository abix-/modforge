// Address: 0x1401b54e0
// Ghidra name: FUN_1401b54e0
// ============ 0x1401b54e0 FUN_1401b54e0 (size=197) ============


undefined8 FUN_1401b54e0(undefined8 *param_1,uint param_2)



{

  int iVar1;

  longlong lVar2;

  uint uVar3;

  ulonglong uVar4;

  uint uVar5;

  undefined8 uVar6;

  uint local_res10 [2];

  

  uVar6 = 0;

  (*DAT_1403fce28)(local_res10,0);

  lVar2 = FUN_1401841f0((ulonglong)local_res10[0] * 0x208);

  (*DAT_1403fce28)(local_res10,lVar2);

  uVar5 = 0;

  if (param_2 != 0) {

    while( true ) {

      uVar6 = 0;

      uVar4 = 0;

      if (local_res10[0] == 0) break;

      while( true ) {

        iVar1 = strcmp((char *)*param_1,(char *)(uVar4 * 0x208 + lVar2));

        if (iVar1 == 0) break;

        uVar3 = (int)uVar4 + 1;

        uVar4 = (ulonglong)uVar3;

        if (local_res10[0] <= uVar3) goto LAB_1401b5585;

      }

      uVar5 = uVar5 + 1;

      param_1 = param_1 + 1;

      uVar6 = 1;

      if (param_2 <= uVar5) break;

    }

  }

LAB_1401b5585:

  FUN_1401841e0(lVar2);

  return uVar6;

}




