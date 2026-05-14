// Address: 0x1401c7440
// Ghidra name: FUN_1401c7440
// ============ 0x1401c7440 FUN_1401c7440 (size=313) ============


undefined8 FUN_1401c7440(longlong param_1,longlong *param_2)



{

  undefined8 uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  longlong local_res8;

  longlong local_res10;

  

  uVar1 = *(undefined8 *)(param_1 + 0x110);

  iVar2 = (**(code **)(**(longlong **)(param_2[1] + 0x10) + 0x40))

                    (*(longlong **)(param_2[1] + 0x10),0,0,&local_res8);

  if (iVar2 < 0) {

    FUN_1401cb240(uVar1,"Failed to map temporary buffer",iVar2);

    return 0;

  }

  iVar2 = (**(code **)(**(longlong **)(*param_2 + 0x10) + 0x40))

                    (*(longlong **)(*param_2 + 0x10),0,0,&local_res10);

  if (-1 < iVar2) {

    uVar5 = 0;

    if ((int)param_2[3] != 0) {

      uVar3 = *(uint *)((longlong)param_2 + 0x14);

      do {

        uVar4 = 0;

        if (uVar3 != 0) {

          do {

            FUN_1402f8e20((ulonglong)*(uint *)((longlong)param_2 + 0x1c) +

                          (ulonglong)((int)param_2[4] * uVar4) + local_res10 +

                          (ulonglong)(uVar5 * *(int *)((longlong)param_2 + 0x24)),

                          (ulonglong)(uVar3 * uVar5) +

                          (ulonglong)(uVar4 * (int)param_2[5]) + local_res8,(int)param_2[4]);

            uVar3 = *(uint *)((longlong)param_2 + 0x14);

            uVar4 = uVar4 + 1;

          } while (uVar4 < uVar3);

        }

        uVar5 = uVar5 + 1;

      } while (uVar5 < *(uint *)(param_2 + 3));

    }

    (**(code **)(**(longlong **)(param_2[1] + 0x10) + 0x48))(*(longlong **)(param_2[1] + 0x10),0,0);

    (**(code **)(**(longlong **)(*param_2 + 0x10) + 0x48))(*(longlong **)(*param_2 + 0x10),0,0);

    return 1;

  }

  FUN_1401cb240(uVar1,"Failed to map destination buffer",iVar2);

  return 0;

}




