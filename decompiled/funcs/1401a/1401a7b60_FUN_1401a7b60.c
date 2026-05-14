// Address: 0x1401a7b60
// Ghidra name: FUN_1401a7b60
// ============ 0x1401a7b60 FUN_1401a7b60 (size=1400) ============


longlong FUN_1401a7b60(longlong param_1,int param_2,uint param_3,int param_4,int param_5,

                      longlong *param_6,uint param_7,int param_8,undefined8 param_9,int param_10,

                      undefined8 param_11,int param_12)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  ulonglong uVar6;

  longlong lVar7;

  longlong lVar8;

  undefined4 local_98 [2];

  undefined1 local_90;

  undefined1 local_8f;

  undefined1 local_8e;

  undefined1 local_8d;

  undefined4 local_8c;

  longlong local_88;

  longlong local_80;

  longlong local_78;

  undefined8 local_70;

  undefined4 local_68;

  undefined4 local_64;

  undefined4 local_60;

  undefined4 local_5c;

  undefined2 local_58;

  undefined1 local_56;

  undefined1 local_55;

  undefined2 local_54;

  undefined1 local_52;

  undefined1 local_51;

  undefined1 local_50;

  undefined1 local_4f;

  undefined4 local_4e;

  undefined2 local_4a;

  undefined1 local_48;

  

  uVar6 = (ulonglong)param_3;

  lVar5 = FUN_1401841f0(0x4df78);

  local_98[0] = 0;

  *param_6 = 0;

  if (lVar5 == 0) {

    return 0;

  }

  local_88 = 0;

  local_70 = 1;

  iVar2 = param_2 * param_4;

  iVar3 = (iVar2 + 1) * param_3;

  if (iVar3 < 0x40) {

    iVar3 = 0x40;

  }

  local_80 = (longlong)(iVar3 + 0x39);

  if (0 < param_10) {

    local_80 = (param_10 + 0xc) + local_80;

  }

  if (0 < param_12) {

    local_80 = local_80 + (param_12 + 0xc);

  }

  local_78 = FUN_1401841f0();

  if (local_78 == 0) {

    FUN_1401841e0(lVar5);

    return 0;

  }

  local_68 = 0x474e5089;

  local_56 = (undefined1)((uint)param_2 >> 8);

  local_52 = (undefined1)(param_3 >> 8);

  local_64 = 0xa1a0a0d;

  local_60 = 0xd000000;

  local_5c = 0x52444849;

  local_58 = 0;

  local_54 = 0;

  local_50 = 8;

  local_4e = 0;

  local_4a = 0;

  local_48 = 0;

  local_51 = (undefined1)param_3;

  if ((param_4 == 1) && (0 < param_10)) {

    local_4f = 3;

  }

  else {

    local_4f = (&DAT_14033bed4)[param_4];

  }

  local_55 = (char)param_2;

  uVar4 = FUN_14019c390(0,&local_5c,0x11);

  local_4e = CONCAT13((char)((uint)uVar4 >> 0x18),(undefined3)local_4e);

  local_4a = CONCAT11((char)((uint)uVar4 >> 8),(char)((uint)uVar4 >> 0x10));

  local_48 = (undefined1)uVar4;

  iVar3 = FUN_1401a7120(&local_68,0x21,&local_88);

  if (iVar3 != 0) {

    if (0 < param_10) {

      local_8c = 0x45544c50;

      local_90 = (undefined1)((uint)param_10 >> 0x18);

      local_8d = (undefined1)param_10;

      local_8f = (undefined1)((uint)param_10 >> 0x10);

      local_8e = (undefined1)((uint)param_10 >> 8);

      iVar3 = FUN_1401a7120(&local_90,8,&local_88);

      lVar1 = local_88;

      if (((iVar3 == 0) || (iVar3 = FUN_1401a7120(param_9,param_10,&local_88), iVar3 == 0)) ||

         (iVar3 = FUN_1401a7120(&DAT_14033c1a0,4,&local_88), iVar3 == 0)) goto LAB_1401a7cf1;

      lVar7 = local_78;

      uVar4 = FUN_14019c390(0,local_78 + -4 + lVar1,(longlong)(param_10 + 4));

      *(char *)(local_88 + -4 + lVar7) = (char)((uint)uVar4 >> 0x18);

      *(char *)(local_88 + -3 + local_78) = (char)((uint)uVar4 >> 0x10);

      *(char *)(local_88 + -2 + local_78) = (char)((uint)uVar4 >> 8);

      *(char *)(local_88 + -1 + local_78) = (char)uVar4;

    }

    if (0 < param_12) {

      local_8c = 0x534e5274;

      local_90 = (undefined1)((uint)param_12 >> 0x18);

      local_8d = (undefined1)param_12;

      local_8f = (undefined1)((uint)param_12 >> 0x10);

      local_8e = (undefined1)((uint)param_12 >> 8);

      iVar3 = FUN_1401a7120(&local_90,8,&local_88);

      lVar1 = local_88;

      if (((iVar3 == 0) || (iVar3 = FUN_1401a7120(param_11,param_12,&local_88), iVar3 == 0)) ||

         (iVar3 = FUN_1401a7120(&DAT_14033c1a0,4,&local_88), iVar3 == 0)) goto LAB_1401a7cf1;

      lVar7 = local_78;

      uVar4 = FUN_14019c390(0,local_78 + -4 + lVar1,(longlong)(param_12 + 4));

      *(char *)(local_88 + -4 + lVar7) = (char)((uint)uVar4 >> 0x18);

      *(char *)(local_88 + -3 + local_78) = (char)((uint)uVar4 >> 0x10);

      *(char *)(local_88 + -2 + local_78) = (char)((uint)uVar4 >> 8);

      *(char *)(local_88 + -1 + local_78) = (char)uVar4;

    }

    iVar3 = FUN_1401a7120(&DAT_14033c1a8,8,&local_88);

    lVar1 = local_88;

    if (iVar3 != 0) {

      if (10 < param_7) {

        param_7 = 10;

      }

      FUN_1401a6d10(lVar5,FUN_1401a7120,&local_88,

                    *(uint *)(&DAT_14033bea8 + (ulonglong)param_7 * 4) | 0x1000);

      if (0 < (int)param_3) {

        if (param_8 == 0) {

          do {

            FUN_1401a5780(lVar5,local_98,1,0);

            FUN_1401a5780(lVar5,param_1,(longlong)iVar2);

            param_1 = param_1 + param_5;

            uVar6 = uVar6 - 1;

          } while (uVar6 != 0);

        }

        else {

          param_1 = (int)((param_3 - 1) * param_5) + param_1;

          do {

            FUN_1401a5780(lVar5,local_98,1,0);

            FUN_1401a5780(lVar5,param_1,(longlong)iVar2);

            param_1 = param_1 + -param_5;

            uVar6 = uVar6 - 1;

          } while (uVar6 != 0);

        }

      }

      iVar2 = FUN_1401a5780(lVar5,0,0,4);

      if (iVar2 != 1) goto LAB_1401a7cf8;

      lVar7 = local_88 - lVar1;

      *(char *)(local_78 + -8 + lVar1) = (char)((ulonglong)lVar7 >> 0x18);

      *(char *)(local_78 + -7 + lVar1) = (char)((ulonglong)lVar7 >> 0x10);

      *(char *)(local_78 + -6 + lVar1) = (char)((ulonglong)lVar7 >> 8);

      *(char *)(local_78 + -5 + lVar1) = (char)lVar7;

      iVar2 = FUN_1401a7120(&DAT_14033c1b8,0x10,&local_88);

      if (iVar2 != 0) {

        lVar8 = local_78;

        uVar4 = FUN_14019c390(0,local_78 + -4 + lVar1,lVar7 + 4);

        *(char *)(local_88 + -0x10 + lVar8) = (char)((uint)uVar4 >> 0x18);

        *(char *)(local_88 + -0xf + local_78) = (char)((uint)uVar4 >> 0x10);

        *(char *)(local_88 + -0xe + local_78) = (char)((uint)uVar4 >> 8);

        *(char *)(local_88 + -0xd + local_78) = (char)uVar4;

        *param_6 = local_88;

        FUN_1401841e0(lVar5);

        return local_78;

      }

    }

  }

LAB_1401a7cf1:

  *param_6 = 0;

LAB_1401a7cf8:

  FUN_1401841e0(lVar5);

  FUN_1401841e0(local_78);

  return 0;

}




