// Address: 0x1401cc650
// Ghidra name: FUN_1401cc650
// ============ 0x1401cc650 FUN_1401cc650 (size=1322) ============


ulonglong FUN_1401cc650(longlong param_1)



{

  longlong lVar1;

  byte bVar2;

  int iVar3;

  ulonglong uVar4;

  undefined8 *puVar5;

  undefined8 uVar6;

  longlong lVar7;

  longlong *plVar8;

  ulonglong uVar9;

  uint uVar10;

  ulonglong uVar11;

  longlong lVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  longlong *local_res8;

  

  lVar1 = *(longlong *)(param_1 + 0x110);

  FUN_140179b40(*(undefined8 *)(lVar1 + 0x210));

  uVar4 = 0;

  if (*(longlong **)(param_1 + 0x470) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x470) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x470) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x610) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x610) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x610) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x478) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x478) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x478) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x618) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x618) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x618) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x480) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x480) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x480) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x620) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x620) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x620) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x488) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x488) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x488) + 0x80) = 0;

  }

  if (*(longlong **)(param_1 + 0x628) != (longlong *)0x0) {

    plVar8 = *(longlong **)(**(longlong **)(param_1 + 0x628) + 0x10);

    (**(code **)(*plVar8 + 0x48))(plVar8,0,0);

    *(undefined8 *)(**(longlong **)(param_1 + 0x628) + 0x80) = 0;

  }

  uVar11 = uVar4;

  if (*(int *)(param_1 + 0x140) != 0) {

    do {

      plVar8 = (longlong *)(uVar11 * 0x10 + *(longlong *)(param_1 + 0x138));

      FUN_1401c9f20((ulonglong)*(uint *)(plVar8 + 1) * 0x50 + *plVar8 + 0x30,0,0);

      (**(code **)(**(longlong **)(param_1 + 0x120) + 0xd0))(*(longlong **)(param_1 + 0x120),1);

      uVar10 = (int)uVar11 + 1;

      uVar11 = (ulonglong)uVar10;

    } while (uVar10 < *(uint *)(param_1 + 0x140));

  }

  iVar3 = (**(code **)(**(longlong **)(param_1 + 0x120) + 0x48))();

  if (iVar3 < 0) {

    uVar4 = FUN_1401cb240(lVar1,"Failed to close command list!",iVar3);

    return uVar4 & 0xffffffffffffff00;

  }

  iVar3 = (**(code **)**(undefined8 **)(param_1 + 0x120))

                    (*(undefined8 **)(param_1 + 0x120),&DAT_140349318,&local_res8);

  if (iVar3 < 0) {

    FUN_140179b60(*(undefined8 *)(lVar1 + 0x210));

    uVar4 = FUN_1401cb240(lVar1,"Failed to convert command list!",iVar3);

    return uVar4 & 0xffffffffffffff00;

  }

  (**(code **)(**(longlong **)(lVar1 + 0x90) + 0x50))(*(longlong **)(lVar1 + 0x90),1,&local_res8);

  (**(code **)(*local_res8 + 0x10))();

  puVar5 = (undefined8 *)FUN_1401c5560(lVar1);

  *(undefined8 **)(param_1 + 0x128) = puVar5;

  if (puVar5 != (undefined8 *)0x0) {

    iVar3 = (**(code **)(**(longlong **)(lVar1 + 0x90) + 0x70))

                      (*(longlong **)(lVar1 + 0x90),*puVar5,1);

    if (-1 < iVar3) {

      uVar10 = *(int *)(lVar1 + 0x128) + 1;

      if (*(uint *)(lVar1 + 300) <= uVar10) {

        *(uint *)(lVar1 + 300) = uVar10;

        uVar6 = FUN_140184230(*(undefined8 *)(lVar1 + 0x120),(ulonglong)uVar10 << 3);

        *(undefined8 *)(lVar1 + 0x120) = uVar6;

      }

      uVar11 = 1;

      *(longlong *)(*(longlong *)(lVar1 + 0x120) + (ulonglong)*(uint *)(lVar1 + 0x128) * 8) =

           param_1;

      *(int *)(lVar1 + 0x128) = *(int *)(lVar1 + 0x128) + 1;

      uVar14 = uVar4;

      if (*(int *)(param_1 + 0x140) != 0) {

        do {

          plVar8 = (longlong *)(uVar14 * 0x10 + *(longlong *)(param_1 + 0x138));

          lVar12 = *plVar8;

          iVar3 = *(int *)(lVar12 + 0x20);

          if ((iVar3 == 1) || (uVar9 = 1, iVar3 == 2)) {

            uVar9 = uVar4;

          }

          uVar13 = uVar4;

          if ((*(int *)(lVar1 + 0x60) != 0) && (uVar13 = 0, iVar3 == 1)) {

            uVar13 = 0x200;

          }

          iVar3 = (**(code **)(**(longlong **)(lVar12 + 0x18) + 0x40))

                            (*(longlong **)(lVar12 + 0x18),uVar9,uVar13);

          if (iVar3 < 0) {

            uVar11 = uVar4;

          }

          (**(code **)(**(longlong **)

                         (*(longlong *)(lVar12 + 0x58 + (ulonglong)*(uint *)(plVar8 + 1) * 0x50) +

                         0x20) + 0x10))();

          *(undefined8 *)(lVar12 + 0x128 + (ulonglong)*(uint *)(lVar12 + 0x2c) * 8) =

               *(undefined8 *)(param_1 + 0x128);

          FUN_140138fb0(*(longlong *)(param_1 + 0x128) + 0x10);

          uVar10 = (int)uVar14 + 1;

          *(uint *)(lVar12 + 0x2c) = (*(int *)(lVar12 + 0x2c) + 1U) % *(uint *)(lVar12 + 0x120);

          uVar14 = (ulonglong)uVar10;

        } while (uVar10 < *(uint *)(param_1 + 0x140));

      }

      iVar3 = *(int *)(lVar1 + 0x128) + -1;

      lVar12 = (longlong)iVar3;

      if (-1 < iVar3) {

        do {

          lVar7 = (**(code **)(*(longlong *)

                                **(undefined8 **)

                                  (*(longlong *)(*(longlong *)(lVar1 + 0x120) + lVar12 * 8) + 0x128)

                              + 0x40))();

          if (lVar7 == 1) {

            bVar2 = FUN_1401c6970(lVar1,*(undefined8 *)(*(longlong *)(lVar1 + 0x120) + lVar12 * 8),0

                                 );

            uVar11 = (ulonglong)(((byte)uVar11 & bVar2) != 0);

          }

          lVar12 = lVar12 + -1;

        } while (-1 < lVar12);

      }

      FUN_1401ca680(lVar1);

      FUN_140179b60(*(undefined8 *)(lVar1 + 0x210));

      return uVar11;

    }

    FUN_140179b60(*(undefined8 *)(lVar1 + 0x210));

    uVar4 = FUN_1401cb240(lVar1,"Failed to enqueue fence signal!",iVar3);

    return uVar4 & 0xffffffffffffff00;

  }

  uVar4 = FUN_140179b60(*(undefined8 *)(lVar1 + 0x210));

  return uVar4 & 0xffffffffffffff00;

}




