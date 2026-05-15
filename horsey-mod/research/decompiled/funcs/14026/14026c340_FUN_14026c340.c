// Address: 0x14026c340
// Ghidra name: FUN_14026c340
// ============ 0x14026c340 FUN_14026c340 (size=1104) ============


ulonglong FUN_14026c340(longlong param_1)



{

  float fVar1;

  float fVar2;

  char cVar3;

  ushort uVar4;

  int iVar5;

  ulonglong uVar6;

  longlong lVar7;

  ushort *puVar8;

  byte bVar9;

  ushort *puVar10;

  ushort *puVar11;

  undefined4 local_res10;

  undefined1 local_res14;

  undefined4 local_res18;

  undefined1 local_res1c;

  ulonglong local_res20;

  ulonglong local_38 [2];

  

  puVar10 = (ushort *)0x0;

  local_res18 = 0x8010;

  local_38[0] = 0;

  local_res20 = 0;

  local_res1c = 0x16;

  bVar9 = 0;

  FUN_14026d5b0(param_1,0x10,&local_res18,5,local_38);

  local_res10 = 0x603d;

  local_res14 = 0x12;

  if (local_38[0] != 0) {

    puVar8 = puVar10;

    if ((*(char *)(local_38[0] + 0x13) == -0x4e) &&

       (puVar8 = (ushort *)0x0, *(char *)(local_38[0] + 0x14) == -0x5f)) {

      bVar9 = 1;

      puVar8 = (ushort *)(local_38[0] + 0x15);

    }

    puVar11 = puVar10;

    if ((*(char *)(local_38[0] + 0x1e) == -0x4e) &&

       (puVar11 = (ushort *)0x0, *(char *)(local_38[0] + 0x1f) == -0x5f)) {

      bVar9 = bVar9 + 1;

      puVar11 = (ushort *)(local_38[0] + 0x20);

    }

    uVar6 = local_38[0];

    if (1 < bVar9) {

LAB_14026c444:

      if ((puVar8 != (ushort *)0x0) && (puVar11 != (ushort *)0x0)) {

        puVar10 = (ushort *)(param_1 + 0x122);

        *puVar10 = *puVar8 & 0xfff;

        *(ushort *)(param_1 + 0x128) =

             (ushort)(byte)puVar8[1] << 4 | (ushort)(*(byte *)((longlong)puVar8 + 1) >> 4);

        *(ushort *)(param_1 + 0x11e) = *(ushort *)((longlong)puVar8 + 3) & 0xfff;

        *(ushort *)(param_1 + 0x124) =

             (ushort)*(byte *)((longlong)puVar8 + 5) << 4 | (ushort)(byte)((byte)puVar8[2] >> 4);

        *(ushort *)(param_1 + 0x120) = puVar8[3] & 0xfff;

        *(ushort *)(param_1 + 0x126) =

             (ushort)(byte)puVar8[4] << 4 | (ushort)(*(byte *)((longlong)puVar8 + 7) >> 4);

        *(ushort *)(param_1 + 0x12a) = *puVar11 & 0xfff;

        *(ushort *)(param_1 + 0x130) =

             (ushort)(byte)puVar11[1] << 4 | (ushort)(*(byte *)((longlong)puVar11 + 1) >> 4);

        *(ushort *)(param_1 + 300) = *(ushort *)((longlong)puVar11 + 3) & 0xfff;

        *(ushort *)(param_1 + 0x132) =

             (ushort)*(byte *)((longlong)puVar11 + 5) << 4 | (ushort)(byte)((byte)puVar11[2] >> 4);

        *(ushort *)(param_1 + 0x12e) = puVar11[3] & 0xfff;

        fVar1 = DAT_140303360;

        *(ushort *)(param_1 + 0x134) =

             (ushort)(byte)puVar11[4] << 4 | (ushort)(*(byte *)((longlong)puVar11 + 7) >> 4);

        lVar7 = 2;

        do {

          uVar4 = puVar10[-2];

          if (uVar4 == 0xfff) {

            puVar10[-2] = 0x800;

            uVar4 = 0x800;

          }

          if (*puVar10 == 0xfff) {

            *puVar10 = (ushort)(int)((float)(int)(short)uVar4 * fVar1);

          }

          if (puVar10[-1] == 0xfff) {

            puVar10[-1] = (ushort)(int)((float)(int)(short)uVar4 * fVar1);

          }

          uVar4 = puVar10[1];

          if (uVar4 == 0xfff) {

            puVar10[1] = 0x800;

            uVar4 = 0x800;

          }

          if (puVar10[3] == 0xfff) {

            puVar10[3] = (ushort)(int)((float)(int)(short)uVar4 * fVar1);

          }

          if (puVar10[2] == 0xfff) {

            puVar10[2] = (ushort)(int)((float)(int)(short)uVar4 * fVar1);

          }

          fVar2 = DAT_14037efa8;

          puVar10 = puVar10 + 6;

          lVar7 = lVar7 + -1;

        } while (lVar7 != 0);

        *(short *)(param_1 + 0x136) =

             (short)(int)((float)(int)*(short *)(param_1 + 0x120) * DAT_14037efa8);

        *(short *)(param_1 + 0x138) = (short)(int)((float)(int)*(short *)(param_1 + 0x122) * fVar1);

        *(short *)(param_1 + 0x13a) = (short)(int)((float)(int)*(short *)(param_1 + 0x126) * fVar2);

        *(short *)(param_1 + 0x13c) = (short)(int)((float)(int)*(short *)(param_1 + 0x128) * fVar1);

        *(short *)(param_1 + 0x13e) = (short)(int)((float)(int)*(short *)(param_1 + 300) * fVar2);

        *(short *)(param_1 + 0x140) = (short)(int)((float)(int)*(short *)(param_1 + 0x12e) * fVar1);

        *(short *)(param_1 + 0x142) = (short)(int)((float)(int)*(short *)(param_1 + 0x132) * fVar2);

        iVar5 = (int)((float)(int)*(short *)(param_1 + 0x134) * fVar1);

        *(short *)(param_1 + 0x144) = (short)iVar5;

        *(undefined4 *)(param_1 + 0x146) = 0x3fffc000;

        *(undefined4 *)(param_1 + 0x14a) = 0x3fffc000;

        *(undefined4 *)(param_1 + 0x14e) = 0x3fffc000;

        *(undefined4 *)(param_1 + 0x152) = 0x3fffc000;

        return CONCAT71((uint7)(uint3)((uint)iVar5 >> 8),1);

      }

      goto LAB_14026c42f;

    }

  }

  uVar6 = FUN_14026d5b0(param_1,0x10,&local_res10,5,&local_res20);

  cVar3 = (char)uVar6;

  while (cVar3 != '\0') {

    uVar6 = local_res20;

    if (*(int *)(local_res20 + 0xe) == 0x603d) {

      puVar8 = (ushort *)(local_res20 + 0x13);

      puVar11 = (ushort *)(local_res20 + 0x1c);

      goto LAB_14026c444;

    }

    if ((int)puVar10 == 3) break;

    puVar10 = (ushort *)(ulonglong)((int)puVar10 + 1);

    uVar6 = FUN_14026d5b0(param_1,0x10,&local_res10,5,&local_res20);

    cVar3 = (char)uVar6;

  }

LAB_14026c42f:

  return uVar6 & 0xffffffffffffff00;

}




