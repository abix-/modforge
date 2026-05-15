// Address: 0x140287f60
// Ghidra name: FUN_140287f60
// ============ 0x140287f60 FUN_140287f60 (size=696) ============


undefined8 FUN_140287f60(longlong param_1,undefined8 param_2,char param_3)



{

  int iVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined4 local_28;

  undefined4 local_24;

  undefined4 uStack_20;

  undefined4 local_1c;

  undefined4 local_18;

  

  puVar2 = (undefined8 *)FUN_1401841a0(1,0x38);

  *(undefined8 **)(param_1 + 0x28) = puVar2;

  if (puVar2 == (undefined8 *)0x0) {

    return 0;

  }

  *puVar2 = param_2;

  *(char *)(*(longlong *)(param_1 + 0x28) + 0x14) = param_3;

  if (param_3 == '\0') {

    iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x68))

                      ((longlong *)**(undefined8 **)(param_1 + 0x28),DAT_1403fcd60,9);

    if (iVar1 < 0) {

      FUN_1402878d0("Setting cooperative level to exclusive",iVar1);

      goto LAB_1402881d1;

    }

    iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x58))

                      ((longlong *)**(undefined8 **)(param_1 + 0x28),&DAT_140380558);

    if (iVar1 < 0) {

      FUN_1402878d0("Setting data format",iVar1);

      goto LAB_1402881d1;

    }

    iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x38))();

    if (iVar1 < 0) {

      FUN_1402878d0("Acquiring DirectInput device",iVar1);

      goto LAB_1402881d1;

    }

  }

  iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x20))

                    ((longlong *)**(undefined8 **)(param_1 + 0x28),FUN_140287610,param_1,3);

  if (iVar1 < 0) {

    FUN_1402878d0("Getting device axes",iVar1);

  }

  else {

    iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0xb0))

                      ((longlong *)**(undefined8 **)(param_1 + 0x28),1);

    if (iVar1 < 0) {

      FUN_1402878d0("Resetting device",iVar1);

    }

    else {

      iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0xb0))

                        ((longlong *)**(undefined8 **)(param_1 + 0x28),0x10);

      if (iVar1 < 0) {

        FUN_1402878d0("Enabling actuators",iVar1);

      }

      else {

        iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x98))

                          ((longlong *)**(undefined8 **)(param_1 + 0x28),FUN_140287720,param_1,0);

        if (iVar1 < 0) {

          FUN_1402878d0("Enumerating supported effects",iVar1);

        }

        else if (*(int *)(param_1 + 0x20) == 0) {

          FUN_14012e850("Haptic: Internal error on finding supported effects.");

        }

        else {

          local_28 = 0x14;

          local_24 = 0x10;

          uStack_20 = 0;

          local_18 = 10000;

          local_1c = 0;

          iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x30))

                            ((longlong *)**(undefined8 **)(param_1 + 0x28),7,&local_28);

          if (-1 < iVar1) {

            *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10000;

          }

          uStack_20 = 0;

          local_1c = 0;

          local_18 = 0;

          iVar1 = (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x30))

                            ((longlong *)**(undefined8 **)(param_1 + 0x28),9,&local_28);

          if (-1 < iVar1) {

            *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20000;

          }

          *(undefined4 *)(param_1 + 0x18) = 0x80;

          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0xc0000;

          *(undefined4 *)(param_1 + 0x1c) = 0x80;

          lVar3 = FUN_1401841f0(0x2800);

          *(longlong *)(param_1 + 0x10) = lVar3;

          if (lVar3 != 0) {

            FUN_1402f94c0(lVar3,0,(longlong)*(int *)(param_1 + 0x18) * 0x50);

            return 1;

          }

        }

      }

    }

  }

LAB_1402881d1:

  (**(code **)(*(longlong *)**(undefined8 **)(param_1 + 0x28) + 0x40))();

  return 0;

}




