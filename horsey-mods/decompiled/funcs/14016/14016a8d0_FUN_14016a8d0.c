// Address: 0x14016a8d0
// Ghidra name: FUN_14016a8d0
// ============ 0x14016a8d0 FUN_14016a8d0 (size=1358) ============


undefined8

FUN_14016a8d0(undefined8 param_1,longlong param_2,uint *param_3,longlong *param_4,

             undefined4 *param_5)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  longlong *plVar7;

  char *pcVar8;

  char *pcVar9;

  undefined1 *puVar10;

  size_t sVar11;

  longlong lVar12;

  uint *puVar13;

  undefined8 uVar14;

  uint uVar15;

  bool bVar16;

  longlong lVar17;

  int iVar18;

  char *pcVar19;

  int local_res10 [2];

  uint *local_res18;

  longlong *local_res20;

  int local_48;

  

  local_res18 = param_3;

  local_res20 = param_4;

  uVar2 = FUN_14016ea50(param_2);

  plVar7 = (longlong *)FUN_140174d30(uVar2,"SDL.internal.window.texturedata",0);

  uVar6 = *(uint *)(param_2 + 0x48);

  FUN_14016ebe0(param_2,local_res10);

  if (plVar7 != (longlong *)0x0) goto LAB_14016ab6f;

  lVar12 = 0;

  pcVar8 = (char *)FUN_140142960("SDL_FRAMEBUFFER_ACCELERATION");

  if (((((((pcVar8 == (char *)0x0) || (*pcVar8 == '0')) || (*pcVar8 == '1')) ||

        (((iVar3 = FUN_14012ef60(pcVar8,&DAT_14031ad1c), iVar3 == 0 ||

          (iVar3 = FUN_14012ef60(pcVar8,"false"), iVar3 == 0)) ||

         (iVar3 = FUN_14012ef60(pcVar8,"software"), iVar3 == 0)))) &&

       (pcVar8 = (char *)FUN_140142960("SDL_RENDER_DRIVER"), pcVar8 == (char *)0x0)) ||

      (iVar3 = FUN_14012ef60(pcVar8,"software"), iVar3 != 0)) &&

     (pcVar9 = (char *)0x0, pcVar8 != (char *)0x0)) {

    if (*pcVar8 != '\0') {

      pcVar9 = (char *)FUN_14012f0d0(pcVar8);

      if (pcVar9 == (char *)0x0) goto LAB_14016aaca;

      puVar10 = (undefined1 *)thunk_FUN_1402c9190(pcVar9,0x2c);

      pcVar19 = pcVar9;

      while (puVar10 != (undefined1 *)0x0) {

        *puVar10 = 0;

        iVar3 = FUN_14012ef60(pcVar19,"software");

        *puVar10 = 0x2c;

        if (iVar3 == 0) {

          sVar11 = strlen("software");

          FUN_1402f94c0(pcVar19,0x78,sVar11);

        }

        else {

          pcVar19 = puVar10 + 1;

        }

        puVar10 = (undefined1 *)thunk_FUN_1402c9190(pcVar19,0x2c);

      }

      iVar3 = FUN_14012ef60(pcVar19,"software");

      pcVar8 = pcVar9;

      if (iVar3 == 0) {

        sVar11 = strlen("software");

        FUN_1402f94c0(pcVar19,0x78,sVar11);

      }

    }

    lVar12 = FUN_14014c6b0(param_2,pcVar8);

    FUN_1401841e0(pcVar9);

    if (lVar12 == 0) {

      return 0;

    }

  }

  else {

LAB_14016aaca:

    iVar3 = FUN_14014e160();

    iVar18 = 0;

    if (iVar3 < 1) {

LAB_14016ad16:

      uVar14 = FUN_14012e850("No hardware accelerated renderers available");

      return uVar14;

    }

    do {

      pcVar8 = (char *)FUN_14014e520(iVar18);

      if (((pcVar8 != (char *)0x0) && (iVar4 = strcmp(pcVar8,"software"), iVar4 != 0)) &&

         (lVar12 = FUN_14014c6b0(param_2,pcVar8), lVar12 != 0)) goto LAB_14016ab24;

      iVar18 = iVar18 + 1;

    } while (iVar18 < iVar3);

    if (lVar12 == 0) goto LAB_14016ad16;

  }

LAB_14016ab24:

  plVar7 = (longlong *)FUN_1401841a0(1,0x20);

  if ((plVar7 == (longlong *)0x0) ||

     (cVar1 = FUN_140175480(uVar2,"SDL.internal.window.texturedata"), cVar1 == '\0')) {

    FUN_14014db70(lVar12);

    return 0;

  }

  *plVar7 = lVar12;

  param_3 = local_res18;

  param_4 = local_res20;

LAB_14016ab6f:

  uVar2 = FUN_14014f090(*plVar7);

  puVar13 = (uint *)FUN_140174d30(uVar2);

  if (puVar13 != (uint *)0x0) {

    if (plVar7[1] != 0) {

      FUN_14014dd50();

      plVar7[1] = 0;

    }

    FUN_1401841e0(plVar7[2]);

    plVar7[2] = 0;

    *param_3 = *puVar13;

    uVar15 = *puVar13;

    if (uVar15 != 0) {

      lVar12 = 0;

      do {

        if ((((((byte)((int)uVar15 >> 0x1c) & 0xf) == 1) &&

             ((((uVar15 & 0xf000000) != 0x6000000 || ((uVar15 & 0xf0000) != 0x70000)) &&

              ((uVar15 & 0xf000000) != 0xa000000)))) &&

            ((((uVar15 & 0xf000000) != 0xb000000 && (uVar5 = uVar15 & 0xf000000, uVar5 != 0x1000000)

              ) && (uVar5 != 0xc000000)))) && ((uVar5 != 0x2000000 && (uVar5 != 0x3000000)))) {

          if ((uVar15 == 0) || ((uVar15 & 0xf0000000) == 0x10000000)) {

            if ((((uVar15 & 0xf000000) != 0x4000000) &&

                (((uVar15 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0)) ||

               ((uVar5 = uVar15 & 0xf00000, uVar5 != 0x300000 &&

                (((uVar5 != 0x400000 && (uVar5 != 0x700000)) && (uVar5 != 0x800000)))))) {

              if (uVar15 != 0) goto LAB_14016acaf;

              goto LAB_14016acbd;

            }

LAB_14016ad27:

            bVar16 = true;

          }

          else {

LAB_14016acaf:

            if ((uVar15 & 0xf0000000) == 0x10000000) {

LAB_14016acbd:

              uVar5 = uVar15 & 0xf000000;

              if (((uVar5 == 0x7000000) ||

                  (((uVar5 + 0xf8000000 & 0xfcffffff) == 0 && (uVar5 != 0xa000000)))) &&

                 ((uVar5 = uVar15 & 0xf00000, uVar5 == 0x300000 ||

                  (((uVar5 == 0x200000 || (uVar5 == 0x600000)) || (uVar5 == 0x500000))))))

              goto LAB_14016ad27;

            }

            bVar16 = false;

          }

          if (((uVar6 & 0x40000000) != 0) == bVar16) {

            *param_3 = uVar15;

            break;

          }

        }

        uVar15 = puVar13[lVar12 + 1];

        lVar12 = lVar12 + 1;

      } while (uVar15 != 0);

    }

    lVar12 = FUN_14014d7f0(*plVar7,*param_3,1,local_res10[0],local_48);

    plVar7[1] = lVar12;

    if (lVar12 != 0) {

      FUN_140154fa0(lVar12,0);

      uVar6 = *param_3;

      if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

        uVar6 = uVar6 & 0xff;

      }

      else if ((((uVar6 == 0x32595559) || (uVar6 == 0x59565955)) || (uVar6 == 0x55595659)) ||

              (uVar6 == 0x30313050)) {

        uVar6 = 2;

      }

      else {

        uVar6 = 1;

      }

      *(uint *)((longlong)plVar7 + 0x1c) = uVar6;

      uVar6 = uVar6 * local_res10[0] + 3 & 0xfffffffc;

      *(uint *)(plVar7 + 3) = uVar6;

      lVar17 = (longlong)(int)uVar6 * (longlong)local_48;

      lVar12 = 1;

      if (lVar17 != 0) {

        lVar12 = lVar17;

      }

      lVar12 = FUN_1401841f0(lVar12);

      plVar7[2] = lVar12;

      if (lVar12 != 0) {

        *param_4 = lVar12;

        *param_5 = (int)plVar7[3];

        FUN_140154e20(*plVar7,0);

        return 1;

      }

    }

  }

  return 0;

}




