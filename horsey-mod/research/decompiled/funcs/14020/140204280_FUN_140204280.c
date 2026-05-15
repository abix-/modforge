// Address: 0x140204280
// Ghidra name: FUN_140204280
// ============ 0x140204280 FUN_140204280 (size=792) ============


longlong FUN_140204280(longlong param_1,undefined4 *param_2)



{

  int iVar1;

  int iVar2;

  longlong lVar3;

  uint *puVar4;

  undefined1 auVar5 [16];

  undefined1 auVar6 [16];

  ulonglong uVar7;

  longlong lVar8;

  longlong lVar9;

  undefined8 uVar10;

  longlong lVar11;

  uint uVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  ulonglong uVar15;

  undefined8 local_res8;

  undefined8 local_res18;

  longlong local_res20;

  undefined4 local_88;

  undefined4 local_84;

  undefined4 local_80;

  longlong local_78;

  undefined4 local_70;

  undefined4 local_6c;

  undefined4 local_68;

  undefined4 local_64;

  undefined8 local_60;

  undefined8 local_58;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  

  lVar3 = *(longlong *)(param_1 + 0x2e0);

  puVar4 = *(uint **)(lVar3 + 0x98);

  if (puVar4 == (uint *)0x0) {

    local_res8 = *(undefined8 *)(lVar3 + 0x58);

    uVar12 = FUN_140137970(*(undefined4 *)(lVar3 + 0x60));

    if (uVar12 == 0) {

      FUN_14012e850("Unsupported backbuffer format");

      return 0;

    }

LAB_1402042be:

    if ((uVar12 & 0xf0000000) != 0x10000000) {

      if ((((uVar12 == 0x32595559) || (uVar12 == 0x59565955)) || (uVar12 == 0x55595659)) ||

         (uVar12 == 0x30313050)) {

        uVar12 = 2;

      }

      else {

        uVar12 = 1;

      }

      goto LAB_14020433a;

    }

  }

  else {

    uVar12 = *puVar4;

    local_res8 = *(undefined8 *)(*(longlong *)(puVar4 + 0x4e) + 8);

    if (uVar12 != 0) goto LAB_1402042be;

  }

  uVar12 = uVar12 & 0xff;

LAB_14020433a:

  iVar1 = param_2[2];

  uVar13 = 0;

  uVar14 = uVar13;

  if ((iVar1 == 0) ||

     (auVar5._8_8_ = 0, auVar5._0_8_ = (longlong)iVar1, uVar14 = (longlong)iVar1,

     (ulonglong)uVar12 <= SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar5,0))) {

    uVar14 = uVar12 * uVar14;

    iVar2 = param_2[3];

    uVar15 = uVar13;

    if ((iVar2 == 0) ||

       (auVar6._8_8_ = 0, auVar6._0_8_ = (longlong)iVar2,

       auVar5 = ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff), uVar7 = SUB168(auVar5 / auVar6,0),

       uVar15 = (longlong)iVar2, uVar14 < uVar7 || uVar14 - uVar7 == 0)) {

      lVar8 = FUN_140145e60(iVar1,iVar2);

      if (lVar8 != 0) {

        local_80 = 0;

        local_84 = (undefined4)(uVar15 * uVar14);

        local_88 = 1;

        lVar9 = FUN_140135d10(*(undefined8 *)(lVar3 + 8),&local_88);

        if (lVar9 != 0) {

          local_res20 = lVar9;

          uVar10 = FUN_140132c70(*(undefined8 *)(lVar3 + 0xa0));

          local_50 = *param_2;

          local_6c = param_2[2];

          local_4c = param_2[1];

          local_68 = param_2[3];

          local_58 = 0;

          local_48 = 0;

          local_60 = local_res8;

          local_3c = 1;

          local_70 = 0;

          local_64 = 0;

          local_78 = lVar9;

          local_44 = local_6c;

          local_40 = local_68;

          FUN_140136100(uVar10,&local_60,&local_78);

          FUN_140136720(uVar10);

          local_res18 = FUN_140138580(*(undefined8 *)(lVar3 + 0xa0));

          FUN_140138b20(*(undefined8 *)(lVar3 + 8),1,&local_res18);

          FUN_140137f10(*(undefined8 *)(lVar3 + 8),local_res18);

          uVar10 = FUN_140132770(*(undefined8 *)(lVar3 + 8));

          *(undefined8 *)(lVar3 + 0xa0) = uVar10;

          lVar11 = FUN_140137ac0(*(undefined8 *)(lVar3 + 8),lVar9,0);

          lVar9 = *(longlong *)(lVar8 + 0x18);

          if ((longlong)*(int *)(lVar8 + 0x10) == uVar14) {

            FUN_1402f8e20(lVar9,lVar11,uVar15 * uVar14);

          }

          else if (0 < (int)param_2[3]) {

            do {

              FUN_1402f8e20(lVar9,lVar11,uVar14);

              lVar11 = lVar11 + uVar14;

              lVar9 = lVar9 + *(int *)(lVar8 + 0x10);

              uVar12 = (int)uVar13 + 1;

              uVar13 = (ulonglong)uVar12;

            } while ((int)uVar12 < (int)param_2[3]);

          }

          FUN_140138720(*(undefined8 *)(lVar3 + 8),local_res20);

          FUN_140138000(*(undefined8 *)(lVar3 + 8),local_res20);

          return lVar8;

        }

      }

    }

    else {

      FUN_14012e850("read size overflow",SUB168(auVar5 % auVar6,0));

    }

  }

  else {

    FUN_14012e850("read size overflow");

  }

  return 0;

}




