// Address: 0x140199320
// Ghidra name: FUN_140199320
// ============ 0x140199320 FUN_140199320 (size=208) ============


void FUN_140199320(longlong *param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  bool bVar3;

  BOOL BVar4;

  longlong lVar5;

  int iVar6;

  

  if (param_1 != (longlong *)0x0) {

    bVar3 = false;

    puVar1 = (undefined8 *)*param_1;

    iVar6 = 0;

    if (0 < *(int *)(puVar1 + 1) + -1) {

      lVar5 = 0;

      do {

        lVar2 = puVar1[2];

        if (*(longlong **)(lVar2 + lVar5) == param_1) {

          bVar3 = true;

LAB_140199364:

          *(undefined8 *)(lVar2 + lVar5) = *(undefined8 *)(lVar2 + 8 + lVar5);

        }

        else if (bVar3) goto LAB_140199364;

        iVar6 = iVar6 + 1;

        lVar5 = lVar5 + 8;

      } while (iVar6 < *(int *)(puVar1 + 1) + -1);

    }

    if (param_1[0x205] != 0) {

      FUN_140198820();

    }

    iVar6 = *(int *)(puVar1 + 1);

    *(int *)(puVar1 + 1) = iVar6 + -1;

    lVar5 = FUN_140184230(puVar1[2],(longlong)iVar6 << 3);

    if (lVar5 != 0) {

      puVar1[2] = lVar5;

      *(undefined8 *)(lVar5 + (longlong)*(int *)(puVar1 + 1) * 8) = 0;

    }

    BVar4 = DeleteMenu((HMENU)*puVar1,*(UINT *)(param_1 + 1),0);

    if (BVar4 == 0) {

      FUN_14012e850("Couldn\'t destroy tray entry");

    }

    FUN_1401841e0(param_1);

  }

  return;

}




