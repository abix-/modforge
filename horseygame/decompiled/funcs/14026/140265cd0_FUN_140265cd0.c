// Address: 0x140265cd0
// Ghidra name: FUN_140265cd0
// ============ 0x140265cd0 FUN_140265cd0 (size=1206) ============


void FUN_140265cd0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  char *_Str1;

  undefined1 auVar1 [16];

  bool bVar2;

  longlong lVar3;

  char cVar4;

  int iVar5;

  byte *pbVar6;

  undefined *puVar7;

  undefined *_Buf1;

  void *_Buf2;

  uint uVar8;

  ulonglong uVar9;

  bool bVar10;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  longlong lStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  longlong local_38;

  

  local_b8 = 0;

  uStack_b0 = 0;

  local_a8 = 0;

  uStack_a0 = 0;

  _Buf1 = (undefined *)0x0;

  local_98 = 0;

  uStack_90 = 0;

  bVar2 = false;

  local_88 = 0;

  uStack_80 = 0;

  local_38 = 0;

  local_78 = 0;

  uStack_70 = 0;

  local_68 = 0;

  lStack_60 = 0;

  local_58 = 0;

  uStack_50 = 0;

  local_48 = 0;

  uStack_40 = 0;

  cVar4 = FUN_140267690(&local_b8,param_3,param_4);

  if (cVar4 == '\0') {

    return;

  }

  if (*(int *)(param_1 + 0x38) == 1) {

    FUN_1402671e0(param_1 + 0x50);

  }

  lVar3 = lStack_60;

  auVar1._8_8_ = uStack_b0;

  auVar1._0_8_ = local_b8;

  *(undefined1 (*) [16])(param_1 + 0x50) = auVar1;

  *(undefined4 *)(param_1 + 0x38) = 1;

  *(undefined8 *)(param_1 + 0x60) = local_a8;

  *(undefined8 *)(param_1 + 0x68) = uStack_a0;

  *(undefined4 *)(param_1 + 0x14c) = 0;

  *(undefined8 *)(param_1 + 0x70) = local_98;

  *(undefined8 *)(param_1 + 0x78) = uStack_90;

  *(undefined4 *)(param_1 + 0x144) = 0xffffffff;

  *(undefined8 *)(param_1 + 0x80) = local_88;

  *(undefined8 *)(param_1 + 0x88) = uStack_80;

  *(undefined8 *)(param_1 + 0x90) = local_78;

  *(undefined8 *)(param_1 + 0x98) = uStack_70;

  *(undefined8 *)(param_1 + 0xa0) = local_68;

  *(longlong *)(param_1 + 0xa8) = lStack_60;

  *(undefined4 *)(param_1 + 0xb0) = (undefined4)local_58;

  *(undefined4 *)(param_1 + 0xb4) = local_58._4_4_;

  *(undefined4 *)(param_1 + 0xb8) = (undefined4)uStack_50;

  *(undefined4 *)(param_1 + 0xbc) = uStack_50._4_4_;

  *(undefined8 *)(param_1 + 0xc0) = local_48;

  *(undefined8 *)(param_1 + 200) = uStack_40;

  *(longlong *)(param_1 + 0xd0) = local_38;

  uVar9 = (ulonglong)uStack_b0 >> 8;

  puVar7 = _Buf1;

  if ((char)((ulonglong)uStack_b0 >> 8) != '\0') {

    do {

      _Str1 = *(char **)(lVar3 + (longlong)puVar7 * 8);

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.Gamepad");

      if (iVar5 == 0) {

        *(undefined4 *)(param_1 + 0x144) = 0;

        _Buf1 = &DAT_14037df40;

        break;

      }

      iVar5 = strcmp(_Str1,"Microsoft.Xbox.Input.ArcadeStick");

      if (iVar5 == 0) {

LAB_140265f60:

        *(undefined4 *)(param_1 + 0x144) = 1;

        _Buf1 = &DAT_14037deb0;

        break;

      }

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.ArcadeStick");

      if (iVar5 == 0) goto LAB_140265f60;

      iVar5 = strcmp(_Str1,"Microsoft.Xbox.Input.FlightStick");

      if (iVar5 == 0) {

LAB_140265f4d:

        *(undefined4 *)(param_1 + 0x144) = 3;

        _Buf1 = &DAT_14037ded0;

        break;

      }

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.FlightStick");

      if (iVar5 == 0) goto LAB_140265f4d;

      iVar5 = strcmp(_Str1,"Microsoft.Xbox.Input.Wheel");

      if (iVar5 == 0) {

LAB_140265f3a:

        *(undefined4 *)(param_1 + 0x144) = 2;

        _Buf1 = &DAT_14037df60;

        break;

      }

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.Wheel");

      if (iVar5 == 0) goto LAB_140265f3a;

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.NavigationController");

      if (iVar5 == 0) {

        *(undefined4 *)(param_1 + 0x144) = 4;

        _Buf1 = &DAT_14037df50;

        break;

      }

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.Chatpad");

      if (iVar5 == 0) {

        *(undefined4 *)(param_1 + 0x144) = 5;

        break;

      }

      iVar5 = strcmp(_Str1,"Windows.Xbox.Input.Headset");

      if (iVar5 == 0) {

        *(undefined4 *)(param_1 + 0x144) = 6;

        _Buf1 = &DAT_14037dee0;

        break;

      }

      puVar7 = puVar7 + 1;

    } while ((longlong)puVar7 < (longlong)(ulonglong)((uint)uVar9 & 0xff));

  }

  bVar10 = _Buf1 == (undefined *)0x0;

  if ((char)((ulonglong)uStack_b0 >> 0x10) != '\0') {

    _Buf2 = (void *)CONCAT44(local_58._4_4_,(undefined4)local_58);

    uVar9 = (ulonglong)((uint)((ulonglong)uStack_b0 >> 0x10) & 0xff);

    do {

      if ((_Buf1 != (undefined *)0x0) && (iVar5 = memcmp(_Buf1,_Buf2,0x10), iVar5 == 0)) {

        bVar10 = true;

      }

      iVar5 = memcmp(&DAT_14037df10,_Buf2,0x10);

      if (iVar5 == 0) {

        bVar2 = true;

      }

      else {

        iVar5 = memcmp(&DAT_14037df20,_Buf2,0x10);

        if (iVar5 == 0) {

          *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 0x10;

        }

        else {

          iVar5 = memcmp(&DAT_14037def0,_Buf2,0x10);

          if (iVar5 == 0) {

            *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 1;

          }

          else {

            iVar5 = memcmp(&DAT_14037df00,_Buf2,0x10);

            if (iVar5 == 0) {

              *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 2;

            }

            else {

              iVar5 = memcmp(&DAT_14037df30,_Buf2,0x10);

              if (iVar5 == 0) {

                *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 4;

              }

              else {

                iVar5 = memcmp(&DAT_14037dec0,_Buf2,0x10);

                if (iVar5 == 0) {

                  *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 8;

                }

              }

            }

          }

        }

      }

      _Buf2 = (void *)((longlong)_Buf2 + 0x10);

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

  }

  uVar9 = (ulonglong)((uint)uStack_40 & 0xff);

  if ((char)uStack_40 != '\0') {

    pbVar6 = (byte *)(local_38 + 8);

    do {

      if (((pbVar6[-8] == 9) && (8 < *(ushort *)(pbVar6 + -6))) && ((*pbVar6 & 8) != 0)) {

        *(uint *)(param_1 + 0x14c) = *(uint *)(param_1 + 0x14c) | 0x20;

      }

      pbVar6 = pbVar6 + 0x10;

      uVar9 = uVar9 - 1;

    } while (uVar9 != 0);

  }

  if ((!bVar10) || ((cVar4 = FUN_140265160(param_1), cVar4 != '\0' && (!bVar2)))) {

    FUN_14012e080(7,

                  "GIP: Controller was missing expected GUID. This controller probably won\'t work on an actual Xbox."

                 );

  }

  uVar8 = *(uint *)(param_1 + 0x14c);

  if (((uVar8 & 0x40) != 0) && (cVar4 = FUN_1402680e0(param_1,0xe,0), cVar4 == '\0')) {

    *(uint *)(param_1 + 0x14c) = uVar8 & 0xffffffbf;

  }

  FUN_140266e50(param_1);

  FUN_140267b60(param_1);

  return;

}




