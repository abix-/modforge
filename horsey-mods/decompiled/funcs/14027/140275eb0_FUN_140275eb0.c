// Address: 0x140275eb0
// Ghidra name: FUN_140275eb0
// ============ 0x140275eb0 FUN_140275eb0 (size=1570) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_140275eb0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  ulonglong uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  char cVar7;

  byte bVar8;

  int iVar9;

  undefined8 uVar10;

  byte bVar11;

  longlong lVar12;

  float fVar13;

  float fVar14;

  longlong local_res8;

  float local_e8;

  float local_e4;

  float local_e0;

  undefined1 local_d8 [176];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  local_res8 = 0;

  if (0 < *(int *)(param_1 + 0x8c)) {

    local_res8 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  lVar12 = local_res8;

  if (*(longlong *)(lVar1 + 0x18) != 0) {

    FUN_140276ae0(lVar1);

  }

  iVar9 = FUN_140276c10(*(undefined8 *)(param_1 + 0x80),local_d8,0x80);

  fVar6 = DAT_14037f684;

  fVar5 = DAT_14037f67c;

  fVar4 = _DAT_1403553cc;

  do {

    if (iVar9 == 0) {

      return 1;

    }

    if (iVar9 < 0) {

      FUN_1402766c0(param_1,&local_res8);

      return 0;

    }

    iVar9 = FUN_140277670(lVar1 + 0x20,local_d8,iVar9);

    if (iVar9 < 1) {

LAB_1402763e0:

      if (*(char *)(lVar1 + 8) == '\0') {

        if (((4 < iVar9) && (*(char *)(lVar1 + 0x20) == '\x01')) &&

           ((*(char *)(lVar1 + 0x21) == '\0' &&

            (((*(char *)(lVar1 + 0x22) == '\x03' && (*(char *)(lVar1 + 0x23) != '\0')) &&

             (*(char *)(lVar1 + 0x24) != '\x01')))))) {

          FUN_140276650(param_1,&local_res8);

          lVar12 = local_res8;

        }

      }

      else if ((((4 < iVar9) && (*(char *)(lVar1 + 0x20) == '\x01')) &&

               (*(char *)(lVar1 + 0x21) == '\0')) &&

              (((*(char *)(lVar1 + 0x22) == '\x03' && (*(char *)(lVar1 + 0x23) != '\0')) &&

               (*(char *)(lVar1 + 0x24) == '\x01')))) {

        FUN_1402766c0(param_1,&local_res8);

        lVar12 = local_res8;

      }

    }

    else {

      cVar7 = FUN_1402774b0(lVar1 + 0x20,iVar9,(undefined8 *)(lVar1 + 0xc0));

      if (cVar7 == '\0') goto LAB_1402763e0;

      uVar10 = FUN_140149300();

      if (*(char *)(lVar1 + 8) == '\0') {

        FUN_140276650(param_1,&local_res8);

        lVar12 = local_res8;

      }

      if (lVar12 != 0) {

        lVar2 = *(longlong *)(lVar1 + 200);

        if (lVar2 != *(longlong *)(lVar1 + 0x120)) {

          FUN_14015ad00(uVar10,lVar12,0,CONCAT71((int7)((ulonglong)lVar2 >> 8),(byte)lVar2 >> 7));

          FUN_14015ad00(uVar10,lVar12,1,*(byte *)(lVar1 + 200) >> 5 & 1);

          FUN_14015ad00(uVar10,lVar12,2,*(byte *)(lVar1 + 200) >> 6 & 1);

          FUN_14015ad00(uVar10,lVar12,3,*(byte *)(lVar1 + 200) >> 4 & 1);

          FUN_14015ad00(uVar10,lVar12,9,*(byte *)(lVar1 + 200) >> 3 & 1);

          FUN_14015ad00(uVar10,lVar12,10,*(byte *)(lVar1 + 200) >> 2 & 1);

          FUN_14015ad00(uVar10,lVar12,4,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x14),

                                 (char)(*(uint *)(lVar1 + 200) >> 0xc)) & 0xffffff01);

          FUN_14015ad00(uVar10,lVar12,6,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x16),

                                 (char)(*(uint *)(lVar1 + 200) >> 0xe)) & 0xffffff01);

          FUN_14015ad00(uVar10,lVar12,5,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x15),

                                 (char)(*(uint *)(lVar1 + 200) >> 0xd)) & 0xffffff01);

          FUN_14015ad00(uVar10,lVar12,7,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x1e),

                                 (char)(*(uint *)(lVar1 + 200) >> 0x16)) & 0xffffff01);

          FUN_14015ad00(uVar10,lVar12,0xc,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x17),

                                 (char)(*(uint *)(lVar1 + 200) >> 0xf)) & 0xffffff01);

          FUN_14015ad00(uVar10,lVar12,0xb,

                        (ushort)((uint)*(undefined4 *)(lVar1 + 200) >> 0x10) & 0xff01);

          FUN_14015ad00(uVar10,lVar12,8,

                        CONCAT31((uint3)(*(uint *)(lVar1 + 200) >> 0x1a),

                                 (char)(*(uint *)(lVar1 + 200) >> 0x12)) & 0xffffff01);

          uVar3 = *(ulonglong *)(lVar1 + 200);

          bVar8 = (byte)(uVar3 >> 8) & 1;

          bVar11 = bVar8 | 4;

          if ((uVar3 & 0x800) == 0) {

            bVar11 = bVar8;

          }

          bVar8 = bVar11 | 8;

          if ((uVar3 & 0x400) == 0) {

            bVar8 = bVar11;

          }

          bVar11 = bVar8 | 2;

          if ((uVar3 & 0x200) == 0) {

            bVar11 = bVar8;

          }

          FUN_14015ae90(uVar10,lVar12,0,bVar11);

        }

        FUN_14015aab0(uVar10,lVar12,4,(*(short *)(lVar1 + 0xe4) + -0x4000) * 2);

        FUN_14015aab0(uVar10,lVar12,5,(*(short *)(lVar1 + 0xe6) + -0x4000) * 2);

        FUN_14015aab0(uVar10,lVar12,0,*(undefined2 *)(lVar1 + 0xdc));

        FUN_14015aab0(uVar10,lVar12,1,~*(ushort *)(lVar1 + 0xde));

        FUN_14015aab0(uVar10,lVar12,2,*(undefined2 *)(lVar1 + 0xd4));

        FUN_14015aab0(uVar10,lVar12,3,~*(ushort *)(lVar1 + 0xd6));

        if (*(char *)(lVar1 + 9) != '\0') {

          *(longlong *)(lVar1 + 0x10) =

               *(longlong *)(lVar1 + 0x10) + (ulonglong)*(uint *)(lVar1 + 0xc) * 1000;

          local_e8 = (float)(int)*(short *)(lVar1 + 0xee) * fVar5 * fVar6;

          local_e4 = (float)(int)*(short *)(lVar1 + 0xf2) * fVar5 * fVar6;

          local_e0 = (float)(int)*(short *)(lVar1 + 0xf0) * fVar5 * fVar6;

          FUN_14015afd0(uVar10,lVar12,2,*(undefined8 *)(lVar1 + 0x10),&local_e8,3);

          fVar13 = (float)(int)*(short *)(lVar1 + 0xe8) * fVar5;

          fVar14 = (float)(int)*(short *)(lVar1 + 0xec) * fVar5;

          local_e8 = (fVar13 + fVar13) * fVar4;

          local_e4 = (fVar14 + fVar14) * fVar4;

          fVar13 = (float)-(int)*(short *)(lVar1 + 0xea) * fVar5;

          local_e0 = (fVar13 + fVar13) * fVar4;

          FUN_14015afd0(uVar10,lVar12,1,*(undefined8 *)(lVar1 + 0x10),&local_e8,3);

        }

        *(undefined8 *)(lVar1 + 0x118) = *(undefined8 *)(lVar1 + 0xc0);

        *(undefined8 *)(lVar1 + 0x120) = *(undefined8 *)(lVar1 + 200);

        *(undefined8 *)(lVar1 + 0x128) = *(undefined8 *)(lVar1 + 0xd0);

        *(undefined8 *)(lVar1 + 0x130) = *(undefined8 *)(lVar1 + 0xd8);

        *(undefined8 *)(lVar1 + 0x138) = *(undefined8 *)(lVar1 + 0xe0);

        *(undefined8 *)(lVar1 + 0x140) = *(undefined8 *)(lVar1 + 0xe8);

        *(undefined8 *)(lVar1 + 0x148) = *(undefined8 *)(lVar1 + 0xf0);

        *(undefined8 *)(lVar1 + 0x150) = *(undefined8 *)(lVar1 + 0xf8);

        *(undefined8 *)(lVar1 + 0x158) = *(undefined8 *)(lVar1 + 0x100);

        *(undefined8 *)(lVar1 + 0x160) = *(undefined8 *)(lVar1 + 0x108);

        *(undefined8 *)(lVar1 + 0x168) = *(undefined8 *)(lVar1 + 0x110);

      }

    }

    iVar9 = FUN_140276c10(*(undefined8 *)(param_1 + 0x80),local_d8,0x80);

  } while( true );

}




