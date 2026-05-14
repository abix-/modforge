// Address: 0x1401a1480
// Ghidra name: FUN_1401a1480
// ============ 0x1401a1480 FUN_1401a1480 (size=289) ============


void FUN_1401a1480(longlong *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong *plVar4;

  longlong lVar5;

  int iVar6;

  longlong lVar7;

  int iVar8;

  

  if (((int)param_1[0x906] != 0) && (iVar6 = 0, 0 < *(int *)(*param_1 + 8))) {

    plVar4 = param_1 + 0x8de;

    do {

      iVar1 = 0;

      iVar2 = *(int *)((longlong)plVar4 + -0x34) + 7 >> 3;

      iVar8 = (int)plVar4[-6] + 7 >> 3;

      if (0 < iVar8) {

        do {

          iVar3 = 0;

          if (0 < iVar2) {

            lVar7 = 0;

            do {

              lVar5 = *plVar4 + (longlong)((iVar1 * (int)plVar4[1] + iVar3) * 0x40) * 2;

              FUN_1401a13d0(lVar5,param_1 + (longlong)*(int *)((longlong)plVar4 + -0x44) * 0x10 +

                                            0x691);

              (*(code *)param_1[0x90e])

                        ((longlong)(*(int *)((longlong)plVar4 + -0x2c) * iVar1 * 8) + plVar4[-4] +

                         lVar7,*(int *)((longlong)plVar4 + -0x2c),lVar5);

              iVar3 = iVar3 + 1;

              lVar7 = lVar7 + 8;

            } while (iVar3 < iVar2);

          }

          iVar1 = iVar1 + 1;

        } while (iVar1 < iVar8);

      }

      iVar6 = iVar6 + 1;

      plVar4 = plVar4 + 0xc;

    } while (iVar6 < *(int *)(*param_1 + 8));

  }

  return;

}




