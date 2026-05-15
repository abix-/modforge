// Address: 0x1402f0198
// Ghidra name: FUN_1402f0198
// ============ 0x1402f0198 FUN_1402f0198 (size=445) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



ulonglong FUN_1402f0198(ulonglong param_1,byte *param_2,ulonglong param_3,uint *param_4,

                       undefined8 param_5)



{

  byte bVar1;

  uint uVar2;

  ulonglong uVar3;

  uint *puVar4;

  byte *pbVar5;

  byte bVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  ulonglong uVar9;

  uint *puVar10;

  undefined1 auStack_78 [24];

  uint auStack_60 [6];

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_78;

  puVar4 = (uint *)&DAT_1403ff650;

  if (param_4 != (uint *)0x0) {

    puVar4 = param_4;

  }

  pbVar5 = &DAT_14039bcb9;

  uVar3 = 1;

  if (param_2 != (byte *)0x0) {

    pbVar5 = param_2;

    uVar3 = param_3;

  }

  puVar10 = (uint *)(-(ulonglong)(param_2 != (byte *)0x0) & param_1);

  if (uVar3 == 0) {

LAB_1402f01fa:

    uVar3 = 0xfffffffffffffffe;

  }

  else {

    if (*(short *)((longlong)puVar4 + 6) == 0) {

      uVar2 = FUN_1402f0160(pbVar5);

      uVar7 = (ulonglong)(int)uVar2;

      bVar1 = *pbVar5;

      pbVar5 = pbVar5 + 1;

      if (uVar2 < 2) {

        if (puVar10 == (uint *)0x0) {

          return uVar7;

        }

        *puVar10 = (uint)bVar1;

        return uVar7;

      }

      if (uVar2 - 2 < 3) {

        bVar6 = (byte)uVar2;

        uVar2 = (1 << (7 - bVar6 & 0x1f)) - 1U & (uint)bVar1;

LAB_1402f0285:

        uVar9 = (ulonglong)bVar6;

        uVar8 = uVar9;

        if (uVar3 <= uVar9) {

          uVar8 = uVar3;

        }

        while ((ulonglong)((longlong)pbVar5 - (longlong)param_2) < uVar8) {

          bVar1 = *pbVar5;

          pbVar5 = pbVar5 + 1;

          if ((bVar1 & 0xc0) != 0x80) goto LAB_1402f032e;

          uVar2 = bVar1 & 0x3f | uVar2 << 6;

        }

        if (uVar8 < uVar9) {

          *(ushort *)(puVar4 + 1) = (ushort)uVar7 & 0xff;

          *(ushort *)((longlong)puVar4 + 6) = (ushort)(byte)(bVar6 - (char)uVar8);

          *puVar4 = uVar2;

          goto LAB_1402f01fa;

        }

        if ((0x7ff < uVar2 - 0xd800) && (uVar2 < 0x110000)) {

          auStack_60[2] = 0x80;

          auStack_60[3] = 0x800;

          auStack_60[4] = 0x10000;

          if (auStack_60[uVar7 & 0xff] <= uVar2) {

            if (puVar10 != (uint *)0x0) {

              *puVar10 = uVar2;

            }

            uVar3 = FUN_1402f7fc0(-(ulonglong)(uVar2 != 0) & uVar9,puVar4);

            return uVar3;

          }

        }

      }

    }

    else {

      bVar1 = (byte)puVar4[1];

      uVar7 = (ulonglong)bVar1;

      uVar2 = *puVar4;

      bVar6 = *(byte *)((longlong)puVar4 + 6);

      if ((((byte)(bVar1 - 2) < 3) && (bVar6 != 0)) && (bVar6 < bVar1)) goto LAB_1402f0285;

    }

LAB_1402f032e:

    uVar3 = FUN_1402f7fc8(puVar4,param_5);

  }

  return uVar3;

}




