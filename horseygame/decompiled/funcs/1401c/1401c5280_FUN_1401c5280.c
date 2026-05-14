// Address: 0x1401c5280
// Ghidra name: FUN_1401c5280
// ============ 0x1401c5280 FUN_1401c5280 (size=515) ============


void FUN_1401c5280(longlong param_1,undefined4 *param_2)



{

  undefined8 *puVar1;

  longlong lVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  undefined4 *local_68;

  int local_60;

  uint local_5c;

  undefined8 local_58;

  uint local_50;

  uint local_4c;

  undefined4 *local_48;

  uint local_40;

  uint local_3c;

  undefined8 local_38;

  uint local_30;

  uint local_2c;

  undefined4 local_28;

  undefined8 local_24;

  undefined8 uStack_1c;

  undefined4 local_14;

  undefined8 local_10;

  

  puVar1 = *(undefined8 **)(param_1 + 0x110);

  lVar2 = FUN_140137340(*puVar1,*param_2,param_2[1],puVar1[0x18],puVar1[0x19],puVar1[0x1a],

                        puVar1[0x1b],puVar1[0x1c],puVar1[0x1d],puVar1 + 0x20,puVar1 + 0x21,

                        (longlong)puVar1 + 0x10c);

  if (lVar2 != 0) {

    uVar5 = 0;

    if (param_2[5] != 0) {

      uVar3 = param_2[6];

      do {

        uVar4 = 1;

        if (1 < uVar3) {

          do {

            local_60 = uVar4 - 1;

            local_14 = 0;

            uVar3 = (uint)param_2[3] >> ((byte)local_60 & 0x1f);

            local_10 = 1;

            local_50 = 1;

            if (1 < uVar3) {

              local_50 = uVar3;

            }

            uVar3 = (uint)param_2[4] >> ((byte)local_60 & 0x1f);

            local_58 = 0;

            local_4c = 1;

            if (1 < uVar3) {

              local_4c = uVar3;

            }

            uVar3 = (uint)param_2[3] >> ((byte)uVar4 & 0x1f);

            local_24 = 0;

            uStack_1c = 0;

            local_30 = 1;

            if (1 < uVar3) {

              local_30 = uVar3;

            }

            uVar3 = (uint)param_2[4] >> ((byte)uVar4 & 0x1f);

            local_38 = 0;

            local_28 = 2;

            local_2c = 1;

            if (1 < uVar3) {

              local_2c = uVar3;

            }

            local_68 = param_2;

            local_5c = uVar5;

            local_48 = param_2;

            local_40 = uVar4;

            local_3c = uVar5;

            FUN_140133e30(param_1,&local_68);

            uVar3 = param_2[6];

            uVar4 = uVar4 + 1;

          } while (uVar4 < uVar3);

        }

        uVar5 = uVar5 + 1;

      } while (uVar5 < (uint)param_2[5]);

    }

    FUN_1401cb900(param_1,*(undefined8 *)(param_2 + 10));

    return;

  }

  FUN_14012e2e0(9,"Could not fetch blit pipeline");

  return;

}




