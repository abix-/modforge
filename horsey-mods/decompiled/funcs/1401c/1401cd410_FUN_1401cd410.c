// Address: 0x1401cd410
// Ghidra name: FUN_1401cd410
// ============ 0x1401cd410 FUN_1401cd410 (size=359) ============


ulonglong FUN_1401cd410(longlong param_1)



{

  longlong *plVar1;

  byte bVar2;

  int iVar3;

  DWORD DVar4;

  undefined8 *puVar5;

  longlong lVar6;

  ulonglong uVar7;

  byte bVar8;

  

  puVar5 = (undefined8 *)FUN_1401c5560();

  uVar7 = 0;

  if (puVar5 == (undefined8 *)0x0) {

LAB_1401cd49c:

    return uVar7 & 0xffffffffffffff00;

  }

  FUN_140179b40(*(undefined8 *)(param_1 + 0x210));

  plVar1 = *(longlong **)(param_1 + 0x90);

  if (plVar1 != (longlong *)0x0) {

    (**(code **)(*plVar1 + 0x70))(plVar1,*puVar5,1);

    lVar6 = (**(code **)(*(longlong *)*puVar5 + 0x40))();

    if (lVar6 != 1) {

      iVar3 = (**(code **)(*(longlong *)*puVar5 + 0x48))((longlong *)*puVar5,1,puVar5[1]);

      if (iVar3 < 0) {

        uVar7 = FUN_1401cb240(param_1,"Setting fence event failed",iVar3);

        goto LAB_1401cd49c;

      }

      DVar4 = WaitForSingleObject((HANDLE)puVar5[1],0xffffffff);

      if (DVar4 == 0xffffffff) {

        FUN_140179b60(*(undefined8 *)(param_1 + 0x210));

        if (*(char *)(param_1 + 0x98) == '\0') {

          uVar7 = FUN_14012e850(&DAT_14039bf30,"Wait failed");

          return uVar7 & 0xffffffffffffff00;

        }

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,&DAT_14039bf30,"Wait failed");

      }

    }

  }

  FUN_1401cbf30(param_1,puVar5);

  bVar8 = 1;

  iVar3 = *(int *)(param_1 + 0x128) + -1;

  lVar6 = (longlong)iVar3;

  if (-1 < iVar3) {

    do {

      bVar2 = FUN_1401c6970(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x120) + lVar6 * 8),0);

      bVar8 = bVar8 & bVar2;

      lVar6 = lVar6 + -1;

    } while (-1 < lVar6);

  }

  FUN_1401ca680(param_1);

  FUN_140179b60(*(undefined8 *)(param_1 + 0x210));

  return (ulonglong)bVar8;

}




