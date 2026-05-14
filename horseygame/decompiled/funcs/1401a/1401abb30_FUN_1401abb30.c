// Address: 0x1401abb30
// Ghidra name: FUN_1401abb30
// ============ 0x1401abb30 FUN_1401abb30 (size=716) ============


void FUN_1401abb30(longlong *param_1,undefined8 *param_2)



{

  ulonglong uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  ulonglong uVar5;

  uint uVar6;

  uint local_res8 [2];

  uint local_res18 [2];

  int local_res20 [2];

  ulonglong local_78;

  undefined4 local_70 [2];

  longlong *local_68;

  longlong *local_60;

  longlong *local_58;

  longlong *local_50;

  undefined1 local_48 [16];

  

  *param_2 = 0;

  param_2[1] = 0;

  local_50 = (longlong *)0x0;

  iVar2 = (**(code **)(*param_1 + 0x40))(0,&local_50);

  if ((-1 < iVar2) && (local_50 != (longlong *)0x0)) {

    local_res18[0] = 0;

    iVar2 = (**(code **)(*local_50 + 0x108))(local_50,local_res18);

    if (iVar2 < 0) {

      local_res18[0] = 0;

    }

    uVar6 = 0;

    if (local_res18[0] != 0) {

      do {

        local_58 = (longlong *)0x0;

        local_res20[0] = 0;

        iVar2 = (**(code **)(*local_50 + 0x110))(local_50,uVar6,local_res20,&local_58);

        if ((-1 < iVar2) && (local_58 != (longlong *)0x0)) {

          if (local_res20[0] != 0) {

            local_60 = (longlong *)0x0;

            iVar2 = (**(code **)(*local_58 + 0x110))(local_58,&local_60);

            if ((-1 < iVar2) && (local_60 != (longlong *)0x0)) {

              local_res8[0] = 0;

              iVar2 = (**(code **)(*local_60 + 0x20))(local_60,local_res8);

              if (iVar2 < 0) {

                local_res8[0] = 0;

              }

              uVar4 = 0;

              if (local_res8[0] != 0) {

                do {

                  local_68 = (longlong *)0x0;

                  iVar2 = (**(code **)(*local_60 + 0x28))(local_60,uVar4,&local_68);

                  if ((-1 < iVar2) && (local_68 != (longlong *)0x0)) {

                    iVar2 = (**(code **)(*local_68 + 0x50))(local_68,&DAT_14033cb10,local_48);

                    if ((-1 < iVar2) && (iVar2 = FUN_1401a98e0(local_48,&DAT_14033cba0), iVar2 != 0)

                       ) {

                      local_78 = local_78 & 0xffffffff00000000;

                      local_70[0] = 0;

                      FUN_1401acc50(local_68,&local_78,local_70);

                      uVar1 = local_78;

                      if ((int)local_78 != 0) {

                        local_78 = 0;

                        iVar2 = (**(code **)(*local_68 + 0x40))(local_68,&DAT_14033cb80,&local_78);

                        uVar5 = local_78 >> 0x20;

                        if ((((-1 < iVar2) && ((int)(local_78 >> 0x20) != 0)) &&

                            (iVar2 = (int)local_78, iVar2 != 0)) &&

                           (((iVar3 = (**(code **)(*local_68 + 0x40))

                                                (local_68,&DAT_14033cb90,&local_78), -1 < iVar3 &&

                             (iVar3 = (int)(local_78 >> 0x20), iVar3 != 0)) && ((int)local_78 != 0))

                           )) {

                          FUN_140130f00(param_2,uVar1 & 0xffffffff,local_70[0],uVar5,iVar2,iVar3,

                                        (int)local_78);

                        }

                      }

                    }

                    (**(code **)(*local_68 + 0x10))();

                  }

                  uVar4 = uVar4 + 1;

                } while (uVar4 < local_res8[0]);

              }

              (**(code **)(*local_60 + 0x10))();

            }

          }

          (**(code **)(*local_58 + 0x10))();

        }

        uVar6 = uVar6 + 1;

      } while (uVar6 < local_res18[0]);

    }

    (**(code **)(*local_50 + 0x10))();

  }

  return;

}




