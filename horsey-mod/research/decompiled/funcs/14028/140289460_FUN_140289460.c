// Address: 0x140289460
// Ghidra name: FUN_140289460
// ============ 0x140289460 FUN_140289460 (size=309) ============


undefined8 FUN_140289460(longlong param_1,undefined8 param_2,int param_3)



{

  int iVar1;

  undefined8 uVar2;

  int local_res8 [2];

  longlong *local_res20;

  longlong *local_68;

  longlong local_60;

  undefined1 local_58 [16];

  undefined1 local_48 [48];

  

  local_res20 = (longlong *)0x0;

  iVar1 = (**(code **)(*DAT_1403fde80 + 0x28))(DAT_1403fde80,param_2,&local_res20);

  if (-1 < iVar1) {

    local_68 = (longlong *)0x0;

    iVar1 = (**(code **)*local_res20)(local_res20,&DAT_140380c88,&local_68);

    if (-1 < iVar1) {

      iVar1 = (**(code **)(*local_68 + 0x18))(local_68,local_res8);

      if (-1 < iVar1) {

        if (param_3 == 1) {

          FUN_140289800(local_res20,&local_60,local_48,local_58);

          if (local_60 != 0) {

            FUN_140289960(local_res8[0] == 1,local_60,local_48,param_2,local_58,

                          *(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10));

            FUN_1401841e0(local_60);

          }

        }

        else {

          uVar2 = FUN_140289b60(param_2);

          (*DAT_1403fde88)(uVar2);

        }

      }

      (**(code **)(*local_68 + 0x10))();

    }

    (**(code **)(*local_res20 + 0x10))();

  }

  return 0;

}




