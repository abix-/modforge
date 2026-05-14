// Address: 0x140222190
// Ghidra name: FUN_140222190
// ============ 0x140222190 FUN_140222190 (size=797) ============


void FUN_140222190(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  longlong *plVar3;

  longlong *plVar4;

  int iVar5;

  longlong lVar6;

  int iVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  undefined8 local_res8;

  

  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x680) + 0x138);

  FUN_140179b40(puVar1[5]);

  lVar6 = FUN_140183290();

  uVar8 = 0;

  uVar9 = uVar8;

  if (0 < *(int *)(puVar1 + 2)) {

    do {

      iVar7 = (int)uVar8;

      puVar2 = *(undefined8 **)(uVar9 + puVar1[3]);

      if (*(char *)((longlong)puVar2 + 0x1c) == '\0') {

        if ((*(byte *)(puVar2[1] + 0x68) & 0x20) != 0) {

          FUN_140160670(*(undefined4 *)(puVar2 + 3),puVar2[2]);

        }

        if ((*(byte *)(puVar2[1] + 0x68) & 0x10) != 0) {

          FUN_140182e30(*(undefined4 *)(puVar2 + 3),puVar2[2]);

        }

        *(undefined1 *)((longlong)puVar2 + 0x1c) = 1;

      }

      if (*(char *)((longlong)puVar2 + 0x1d) == '\0') {

        if (((*(uint *)(puVar2[1] + 0x68) & *(uint *)(puVar1 + 4)) != 0) && (lVar6 != 0)) {

          if ((*(uint *)(puVar1 + 4) & 0x20) != 0) {

            plVar3 = (longlong *)*puVar1;

            if (puVar2[4] == 0) {

              iVar5 = (**(code **)(*plVar3 + 0x20))(plVar3,0x20);

              if (-1 < iVar5) {

                FUN_140221ba0(puVar1,lVar6,puVar2,local_res8);

                goto LAB_14022234c;

              }

            }

            else {

              iVar5 = (**(code **)(*plVar3 + 0x28))(plVar3,puVar2[4],0x20,*puVar2,&local_res8);

              while (-1 < iVar5) {

                FUN_140221840(puVar1,lVar6,puVar2,puVar2[4],local_res8);

                (**(code **)(*(longlong *)puVar2[4] + 0x10))();

                puVar2[4] = local_res8;

                iVar5 = (**(code **)(*(longlong *)*puVar1 + 0x28))

                                  ((longlong *)*puVar1,local_res8,0x20,*puVar2,&local_res8);

              }

              if ((iVar5 != -0x7c75fffd) &&

                 (iVar5 = (**(code **)(*(longlong *)*puVar1 + 0x20))

                                    ((longlong *)*puVar1,0x20,*puVar2,&local_res8), -1 < iVar5)) {

                FUN_140221840(puVar1,lVar6,puVar2,puVar2[4],local_res8);

                (**(code **)(*(longlong *)puVar2[4] + 0x10))();

LAB_14022234c:

                puVar2[4] = local_res8;

              }

            }

          }

          if ((*(byte *)(puVar1 + 4) & 0x10) != 0) {

            plVar3 = (longlong *)puVar2[5];

            if (*(char *)(lVar6 + 0x138) == '\0') {

              plVar4 = (longlong *)*puVar1;

              if (plVar3 == (longlong *)0x0) {

                iVar5 = (**(code **)(*plVar4 + 0x20))(plVar4,0x10,*puVar2,&local_res8);

                if (-1 < iVar5) {

                  FUN_140221a50(puVar1,lVar6,puVar2,local_res8);

                  goto LAB_140222474;

                }

              }

              else {

                iVar5 = (**(code **)(*plVar4 + 0x28))(plVar4,plVar3,0x10,*puVar2,&local_res8);

                while (-1 < iVar5) {

                  FUN_1402216a0(puVar1,lVar6,puVar2,puVar2[5],local_res8);

                  (**(code **)(*(longlong *)puVar2[5] + 0x10))();

                  puVar2[5] = local_res8;

                  iVar5 = (**(code **)(*(longlong *)*puVar1 + 0x28))

                                    ((longlong *)*puVar1,local_res8,0x10,*puVar2,&local_res8);

                }

                if ((iVar5 != -0x7c75fffd) &&

                   (iVar5 = (**(code **)(*(longlong *)*puVar1 + 0x20))

                                      ((longlong *)*puVar1,0x10,*puVar2,&local_res8), -1 < iVar5)) {

                  FUN_1402216a0(puVar1,lVar6,puVar2,puVar2[5],local_res8);

                  (**(code **)(*(longlong *)puVar2[5] + 0x10))();

LAB_140222474:

                  puVar2[5] = local_res8;

                }

              }

            }

            else if (plVar3 != (longlong *)0x0) {

              (**(code **)(*plVar3 + 0x10))(plVar3);

              puVar2[5] = 0;

            }

          }

        }

      }

      else {

        FUN_140221de0(puVar1,uVar8);

        iVar7 = iVar7 + -1;

        uVar9 = uVar9 - 8;

      }

      uVar8 = (ulonglong)(iVar7 + 1U);

      uVar9 = uVar9 + 8;

    } while ((int)(iVar7 + 1U) < *(int *)(puVar1 + 2));

  }

  FUN_140179b60(puVar1[5]);

  return;

}




