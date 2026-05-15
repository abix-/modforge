// Address: 0x140265a30
// Ghidra name: FUN_140265a30
// ============ 0x140265a30 FUN_140265a30 (size=669) ============


undefined8 FUN_140265a30(longlong param_1,undefined8 param_2,byte *param_3,int param_4)



{

  byte bVar1;

  uint uVar2;

  undefined8 uVar3;

  int iVar4;

  byte bVar5;

  undefined4 local_res8 [2];

  

  uVar3 = FUN_140149300();

  if (((*(int *)(param_1 + 0x144) == 5) && (*(int *)(param_1 + 0x10) != 0)) && (param_4 == 8)) {

    bVar1 = *param_3;

    bVar5 = bVar1 ^ *(byte *)(param_1 + 0x135);

    if ((bVar5 & 2) != 0) {

      FUN_140183990(uVar3,*(int *)(param_1 + 0x10),0,0xe1,(bVar1 & 2) != 0);

    }

    if ((bVar5 & 4) != 0) {

      if ((bVar1 & 4) == 0) {

        if (*(int *)(param_1 + 0x140) == 4) {

          iVar4 = *(int *)(param_1 + 0x13c);

          local_res8[0] = 0;

          if (iVar4 == 0x80) {

            iVar4 = 0x20ac;

          }

          else if (iVar4 == 0x8a) {

            iVar4 = 0x160;

          }

          else if (iVar4 == 0x8c) {

            iVar4 = 0x152;

          }

          else if (iVar4 == 0x9a) {

            iVar4 = 0x161;

          }

          else if (iVar4 == 0x9c) {

            iVar4 = 0x153;

          }

          FUN_14012ed70(iVar4,local_res8);

          FUN_140183cd0(local_res8);

        }

        *(undefined4 *)(param_1 + 0x140) = 0xffffffff;

        FUN_140183990(uVar3,*(undefined4 *)(param_1 + 0x10),0,0x53,1);

        FUN_140183990(uVar3,*(undefined4 *)(param_1 + 0x10),0,0x53,0);

      }

      else {

        *(undefined8 *)(param_1 + 0x13c) = 0;

      }

    }

    if ((param_3[2] == 0) && (uVar2 = *(uint *)(param_1 + 0x138), uVar2 != 0)) {

      if (uVar2 == 0x39) {

        *(bool *)(param_1 + 0x136) = *(char *)(param_1 + 0x136) == '\0';

      }

      FUN_140183990(uVar3,*(undefined4 *)(param_1 + 0x10),0,uVar2,0);

      if ((*(byte *)(param_1 + 0x135) & 0xfd) == 0) {

        if (((*(byte *)(param_1 + 0x135) & 2) == 0) && (*(char *)(param_1 + 0x136) == '\0')) {

          uVar3 = 0;

        }

        else {

          uVar3 = 3;

        }

        uVar2 = FUN_1401829a0(0,*(undefined4 *)(param_1 + 0x138),uVar3);

        if ((uVar2 != 0) && (uVar2 < 0x80)) {

          local_res8[0]._0_2_ = (ushort)(byte)uVar2;

          FUN_140183cd0(local_res8);

        }

      }

      *(undefined4 *)(param_1 + 0x138) = 0;

    }

    else {

      FUN_140183990(uVar3,*(undefined4 *)(param_1 + 0x10),0,param_3[2],1);

      *(uint *)(param_1 + 0x138) = (uint)param_3[2];

      if (((bVar1 & 4) != 0) && (-1 < *(int *)(param_1 + 0x140))) {

        bVar5 = param_3[2];

        if ((bVar5 < 0x59) || (0x62 < bVar5)) {

          *(undefined4 *)(param_1 + 0x140) = 0xffffffff;

        }

        else {

          *(int *)(param_1 + 0x140) = *(int *)(param_1 + 0x140) + 1;

          iVar4 = *(int *)(param_1 + 0x13c) * 10;

          *(int *)(param_1 + 0x13c) = iVar4;

          if (bVar5 < 0x62) {

            *(uint *)(param_1 + 0x13c) = (bVar5 - 0x58) + iVar4;

          }

        }

      }

    }

    *(byte *)(param_1 + 0x135) = bVar1;

    return 1;

  }

  FUN_14012e080(7,"GIP: Unimplemented HID Report message");

  return 0;

}




