// Address: 0x1401c0990
// Ghidra name: FUN_1401c0990
// ============ 0x1401c0990 FUN_1401c0990 (size=380) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



undefined8 FUN_1401c0990(longlong param_1,undefined1 param_2,longlong param_3,uint param_4)



{

  undefined8 *puVar1;

  code *pcVar2;

  undefined8 uVar3;

  longlong lVar4;

  int iVar5;

  undefined8 uVar6;

  ulonglong uVar7;

  undefined8 *puVar8;

  ulonglong uVar9;

  longlong lVar10;

  undefined8 auStack_40 [5];

  undefined8 auStack_18 [2];

  

  uVar9 = (ulonglong)param_4;

  uVar7 = (ulonglong)param_4 * 8 + 0xf;

  if (uVar7 <= (ulonglong)param_4 * 8) {

    uVar7 = 0xffffffffffffff0;

  }

  auStack_40[0] = 0x1401c09da;

  lVar4 = -(uVar7 & 0xfffffffffffffff0);

  puVar1 = (undefined8 *)(&stack0xfffffffffffffff8 + lVar4);

  if (param_4 != 0) {

    puVar8 = puVar1;

    do {

      *puVar8 = **(undefined8 **)((longlong)puVar8 + (param_3 - (longlong)puVar1));

      uVar9 = uVar9 - 1;

      puVar8 = puVar8 + 1;

    } while (uVar9 != 0);

  }

  pcVar2 = *(code **)(param_1 + 0xc80);

  uVar6 = *(undefined8 *)(param_1 + 0x570);

  *(undefined8 *)((longlong)auStack_18 + lVar4) = 0xffffffffffffffff;

  *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a23;

  iVar5 = (*pcVar2)(uVar6,param_4,puVar1,param_2);

  if (iVar5 != 0) {

    if (*(char *)(param_1 + 0x57c) != '\0') {

      *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a39;

      uVar6 = FUN_1401c0ba0(iVar5);

                    /* WARNING: Subroutine does not return */

      *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a54;

      FUN_14012e0b0(9,"%s %s","vkWaitForFences",uVar6);

    }

    *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a5b;

    uVar6 = FUN_1401c0ba0(iVar5);

    *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a71;

    FUN_14012e850("%s %s","vkWaitForFences",uVar6);

    return 0;

  }

  uVar6 = *(undefined8 *)(param_1 + 0x8d0);

  *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0a90;

  FUN_140179b40(uVar6);

  iVar5 = *(int *)(param_1 + 0x7d8) + -1;

  lVar10 = (longlong)iVar5;

  if (-1 < iVar5) {

    do {

      pcVar2 = *(code **)(param_1 + 0xc20);

      uVar6 = *(undefined8 *)(param_1 + 0x570);

      uVar3 = **(undefined8 **)(*(longlong *)(*(longlong *)(param_1 + 2000) + lVar10 * 8) + 0xa90);

      *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0ac5;

      iVar5 = (*pcVar2)(uVar6,uVar3);

      if (iVar5 == 0) {

        uVar6 = *(undefined8 *)(*(longlong *)(param_1 + 2000) + lVar10 * 8);

        *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0adf;

        FUN_1401b55b0(param_1,uVar6,0);

      }

      lVar10 = lVar10 + -1;

    } while (-1 < lVar10);

  }

  *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0aed;

  FUN_1401bbb60(param_1);

  uVar6 = *(undefined8 *)(param_1 + 0x8d0);

  *(undefined8 *)((longlong)auStack_40 + lVar4) = 0x1401c0af9;

  FUN_140179b60(uVar6);

  return 1;

}




