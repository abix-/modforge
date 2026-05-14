// Address: 0x140221840
// Ghidra name: FUN_140221840
// ============ 0x140221840 FUN_140221840 (size=528) ============


void FUN_140221840(longlong param_1,longlong param_2,longlong param_3,longlong *param_4,

                  longlong *param_5)



{

  undefined4 uVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  uint uVar5;

  undefined1 *puVar6;

  uint uVar7;

  longlong lVar8;

  float fVar9;

  float fVar10;

  uint local_a8 [2];

  longlong local_a0;

  longlong local_98;

  longlong local_90;

  longlong local_88;

  uint local_80 [2];

  longlong local_78;

  longlong local_70;

  longlong local_68;

  longlong local_60;

  

  cVar2 = (**(code **)(*param_4 + 0x80))(param_4,local_80);

  if ((cVar2 != '\0') && (cVar2 = (**(code **)(*param_5 + 0x80))(param_5,local_a8), cVar2 != '\0'))

  {

    lVar8 = *(longlong *)(param_1 + 0x30);

    lVar3 = (**(code **)(*param_5 + 0x28))(param_5);

    uVar7 = local_a8[0] ^ local_80[0];

    uVar1 = *(undefined4 *)(param_3 + 0x18);

    lVar8 = (lVar3 + lVar8) * 1000;

    if ((local_a0 - local_78 != 0) || (local_98 - local_70 != 0)) {

      FUN_1401628f0(lVar8,param_2,uVar1,1,(float)(local_a0 - local_78),(float)(local_98 - local_70))

      ;

    }

    if (uVar7 != 0) {

      uVar5 = 1;

      puVar6 = &DAT_140356300;

      lVar3 = 7;

      do {

        if ((uVar5 & uVar7) != 0) {

          FUN_1401628d0(lVar8,param_2,uVar1,*puVar6,(local_a8[0] & uVar5) != 0);

        }

        uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);

        puVar6 = puVar6 + 1;

        lVar3 = lVar3 + -1;

      } while (lVar3 != 0);

      *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 0x50) = 0xffffffffffffffff;

    }

    if ((local_90 - local_68 != 0) || (local_88 - local_60 != 0)) {

      uVar1 = *(undefined4 *)(param_3 + 0x18);

      fVar10 = (float)(local_88 - local_60) / DAT_140303758;

      fVar9 = (float)(local_90 - local_68) / DAT_140303758;

      uVar4 = FUN_140161230();

      FUN_1401629c0(lVar8,uVar4,uVar1,fVar9,fVar10,0);

    }

  }

  return;

}




