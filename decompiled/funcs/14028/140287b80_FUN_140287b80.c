// Address: 0x140287b80
// Ghidra name: FUN_140287b80
// ============ 0x140287b80 FUN_140287b80 (size=535) ============


ulonglong FUN_140287b80(undefined8 *param_1)



{

  undefined8 uVar1;

  undefined8 *puVar2;

  int iVar3;

  undefined4 uVar4;

  ulonglong in_RAX;

  undefined4 extraout_var;

  undefined4 *puVar5;

  longlong lVar6;

  ulonglong uVar7;

  undefined8 *puVar8;

  undefined8 *puVar9;

  longlong *local_res10;

  undefined4 local_38;

  uint uStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 uStack_28;

  undefined8 uStack_24;

  undefined4 uStack_1c;

  undefined4 uStack_18;

  undefined4 local_14;

  undefined4 uStack_10;

  

  lVar6 = DAT_1403fdb58;

  if (DAT_1403fde60 != (longlong *)0x0) {

    for (; lVar6 != 0; lVar6 = *(longlong *)(lVar6 + 0x490)) {

      iVar3 = memcmp((void *)(lVar6 + 0x18),param_1,0x44c);

      in_RAX = CONCAT44(extraout_var,iVar3);

      if (iVar3 == 0) goto LAB_140287cb4;

    }

    in_RAX = (**(code **)(*DAT_1403fde60 + 0x18))

                       (DAT_1403fde60,(longlong)param_1 + 4,&local_res10,0);

    if (-1 < (int)in_RAX) {

      local_14 = 0;

      uStack_10 = 0;

      uStack_34 = 0;

      uStack_30 = 0;

      uStack_2c = 0;

      uStack_28 = 0;

      local_38 = 0x2c;

      uStack_24 = 0;

      uStack_1c = 0;

      uStack_18 = 0;

      iVar3 = (**(code **)(*local_res10 + 0x18))(local_res10,&local_38);

      in_RAX = (**(code **)(*local_res10 + 0x10))();

      if ((-1 < iVar3) && (in_RAX = (ulonglong)(uStack_34 & 0x101), (uStack_34 & 0x101) == 0x101)) {

        puVar5 = (undefined4 *)FUN_1401841a0(1,0x498);

        in_RAX = 0;

        if (puVar5 != (undefined4 *)0x0) {

          uVar4 = FUN_1401aa810();

          *puVar5 = uVar4;

          lVar6 = FUN_14012fd40(param_1 + 0x46);

          lVar6 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",param_1 + 0x46,lVar6 * 2 + 2);

          *(longlong *)(puVar5 + 2) = lVar6;

          if (lVar6 != 0) {

            lVar6 = 8;

            puVar2 = (undefined8 *)(puVar5 + 6);

            do {

              puVar9 = param_1;

              puVar8 = puVar2;

              uVar1 = puVar9[1];

              *puVar8 = *puVar9;

              puVar8[1] = uVar1;

              uVar1 = puVar9[3];

              puVar8[2] = puVar9[2];

              puVar8[3] = uVar1;

              uVar1 = puVar9[5];

              puVar8[4] = puVar9[4];

              puVar8[5] = uVar1;

              uVar1 = puVar9[7];

              puVar8[6] = puVar9[6];

              puVar8[7] = uVar1;

              uVar1 = puVar9[9];

              puVar8[8] = puVar9[8];

              puVar8[9] = uVar1;

              uVar1 = puVar9[0xb];

              puVar8[10] = puVar9[10];

              puVar8[0xb] = uVar1;

              uVar1 = puVar9[0xd];

              puVar8[0xc] = puVar9[0xc];

              puVar8[0xd] = uVar1;

              uVar1 = puVar9[0xf];

              puVar8[0xe] = puVar9[0xe];

              puVar8[0xf] = uVar1;

              lVar6 = lVar6 + -1;

              puVar2 = puVar8 + 0x10;

              param_1 = puVar9 + 0x10;

            } while (lVar6 != 0);

            uVar1 = puVar9[0x11];

            puVar8[0x10] = puVar9[0x10];

            puVar8[0x11] = uVar1;

            uVar1 = puVar9[0x13];

            puVar8[0x12] = puVar9[0x12];

            puVar8[0x13] = uVar1;

            uVar1 = puVar9[0x15];

            puVar8[0x14] = puVar9[0x14];

            puVar8[0x15] = uVar1;

            uVar1 = puVar9[0x17];

            puVar8[0x16] = puVar9[0x16];

            puVar8[0x17] = uVar1;

            puVar8[0x18] = puVar9[0x18];

            *(undefined4 *)(puVar8 + 0x19) = *(undefined4 *)(puVar9 + 0x19);

            *(ulonglong *)(puVar5 + 0x119) = CONCAT44(uStack_34,local_38);

            *(ulonglong *)(puVar5 + 0x11b) = CONCAT44(uStack_2c,uStack_30);

            puVar5[0x11d] = uStack_28;

            puVar5[0x11e] = (undefined4)uStack_24;

            puVar5[0x11f] = uStack_24._4_4_;

            puVar5[0x120] = uStack_1c;

            *(ulonglong *)(puVar5 + 0x121) = CONCAT44(local_14,uStack_18);

            puVar5[0x123] = uStack_10;

            uVar7 = FUN_14021ab50(puVar5);

            return uVar7;

          }

          in_RAX = FUN_1401841e0(puVar5);

        }

      }

    }

  }

LAB_140287cb4:

  return in_RAX & 0xffffffffffffff00;

}




