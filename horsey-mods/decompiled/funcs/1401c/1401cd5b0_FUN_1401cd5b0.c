// Address: 0x1401cd5b0
// Ghidra name: FUN_1401cd5b0
// ============ 0x1401cd5b0 FUN_1401cd5b0 (size=441) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



ulonglong FUN_1401cd5b0(longlong param_1,byte param_2,longlong param_3,uint param_4)



{

  HANDLE *lpHandles;

  undefined8 uVar1;

  undefined8 *puVar2;

  longlong *plVar3;

  code *pcVar4;

  longlong lVar5;

  byte bVar6;

  int iVar7;

  DWORD DVar8;

  longlong lVar9;

  ulonglong uVar10;

  uint uVar11;

  HANDLE *ppvVar12;

  longlong lVar13;

  bool bVar14;

  undefined8 auStack_50 [5];

  

  uVar10 = (ulonglong)param_4 * 8 + 0xf;

  if (uVar10 <= (ulonglong)param_4 * 8) {

    uVar10 = 0xffffffffffffff0;

  }

  auStack_50[0] = 0x1401cd601;

  lVar5 = -(uVar10 & 0xfffffffffffffff0);

  uVar1 = *(undefined8 *)(param_1 + 0x210);

  lpHandles = (HANDLE *)(&stack0xffffffffffffffd8 + lVar5);

  *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd615;

  FUN_140179b40(uVar1);

  uVar11 = 0;

  if (param_4 != 0) {

    ppvVar12 = lpHandles;

    do {

      puVar2 = *(undefined8 **)((longlong)ppvVar12 + (param_3 - (longlong)lpHandles));

      plVar3 = (longlong *)*puVar2;

      uVar1 = puVar2[1];

      pcVar4 = *(code **)(*plVar3 + 0x48);

      *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd64a;

      iVar7 = (*pcVar4)(plVar3,1,uVar1);

      if (iVar7 < 0) {

        *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd6d5;

        uVar10 = FUN_1401cb240(param_1,"Setting fence event failed",iVar7);

        return uVar10 & 0xffffffffffffff00;

      }

      uVar11 = uVar11 + 1;

      *ppvVar12 = (HANDLE)puVar2[1];

      ppvVar12 = ppvVar12 + 1;

    } while (uVar11 < param_4);

  }

  *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd677;

  DVar8 = WaitForMultipleObjects(param_4,lpHandles,(uint)param_2,0xffffffff);

  if (DVar8 == 0xffffffff) {

    uVar1 = *(undefined8 *)(param_1 + 0x210);

    *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd688;

    FUN_140179b60(uVar1);

    if (*(char *)(param_1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd6a9;

      FUN_14012e0b0(9,&DAT_14039bf30,"Wait failed");

    }

    *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd6bc;

    uVar10 = FUN_14012e850(&DAT_14039bf30,"Wait failed");

    uVar10 = uVar10 & 0xffffffffffffff00;

  }

  else {

    bVar14 = true;

    iVar7 = *(int *)(param_1 + 0x128) + -1;

    lVar13 = (longlong)iVar7;

    if (-1 < iVar7) {

      do {

        pcVar4 = *(code **)(*(longlong *)

                             **(undefined8 **)

                               (*(longlong *)(*(longlong *)(param_1 + 0x120) + lVar13 * 8) + 0x128)

                           + 0x40);

        *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd70f;

        lVar9 = (*pcVar4)();

        if (lVar9 == 1) {

          uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x120) + lVar13 * 8);

          *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd72b;

          bVar6 = FUN_1401c6970(param_1,uVar1,0);

          bVar14 = (bVar14 & bVar6) != 0;

        }

        lVar13 = lVar13 + -1;

      } while (-1 < lVar13);

    }

    *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd740;

    FUN_1401ca680(param_1);

    uVar1 = *(undefined8 *)(param_1 + 0x210);

    *(undefined8 *)((longlong)auStack_50 + lVar5) = 0x1401cd74c;

    FUN_140179b60(uVar1);

    uVar10 = (ulonglong)bVar14;

  }

  return uVar10;

}




