// Address: 0x1401f3710
// Ghidra name: FUN_1401f3710
// ============ 0x1401f3710 FUN_1401f3710 (size=1166) ============


undefined8

FUN_1401f3710(longlong param_1,longlong param_2,int param_3,int param_4,undefined4 param_5)



{

  bool bVar1;

  char cVar2;

  byte bVar3;

  int iVar4;

  undefined4 *puVar5;

  undefined4 *puVar6;

  longlong lVar7;

  undefined8 uVar8;

  ulonglong uVar9;

  uint uVar10;

  undefined4 *puVar11;

  undefined4 *puVar12;

  uint local_res18;

  undefined4 local_58;

  undefined4 local_54;

  undefined4 local_50;

  undefined4 local_4c;

  undefined4 local_48;

  undefined4 local_44;

  undefined4 local_40;

  undefined4 local_3c;

  undefined4 local_38;

  

  puVar11 = (undefined4 *)0x0;

  puVar6 = puVar11;

  if (param_2 != 0) {

    puVar6 = *(undefined4 **)(param_2 + 0x138);

  }

  if ((*(int **)(param_1 + 0x280) == (int *)0x0) ||

     ((iVar4 = **(int **)(param_1 + 0x280), iVar4 != 0x16362004 && (iVar4 != 0x16161804)))) {

    bVar1 = false;

  }

  else {

    bVar1 = true;

  }

  puVar5 = puVar11;

  puVar12 = puVar11;

  switch(param_3 + -1) {

  case 0:

    uVar9 = 1;

    break;

  case 1:

    if (param_4 == 0) {

      puVar5 = (undefined4 *)0x0;

      puVar12 = (undefined4 *)0x0;

      if (bVar1) {

        uVar9 = 5;

      }

      else {

        uVar9 = 2;

      }

    }

    else {

      if (param_4 == 1) {

        uVar9 = 6;

        uVar10 = 3;

      }

      else {

        if (param_4 != 2) goto switchD_1401f37a0_default;

        uVar9 = 7;

        uVar10 = 4;

      }

      puVar5 = puVar6 + 0xe;

      puVar12 = (undefined4 *)0x10;

      if (!bVar1) {

        uVar9 = (ulonglong)uVar10;

      }

    }

    break;

  case 2:

    if (param_4 == 2) {

      puVar5 = puVar6 + 0xe;

    }

    uVar9 = (ulonglong)((param_4 == 2) + 0xe);

    goto LAB_1401f382c;

  case 3:

    if (param_4 == 2) {

      puVar5 = puVar6 + 0xe;

    }

    uVar9 = (ulonglong)((param_4 == 2) + 0xc);

    goto LAB_1401f382c;

  case 4:

    if (param_4 == 2) {

      puVar5 = puVar6 + 0xe;

    }

    uVar9 = (ulonglong)((param_4 == 2) + 8);

    goto LAB_1401f382c;

  case 5:

    if (param_4 == 2) {

      puVar5 = puVar6 + 0xe;

    }

    uVar9 = (ulonglong)((param_4 == 2) + 10);

LAB_1401f382c:

    puVar12 = (undefined4 *)0x10;

    if (param_4 != 2) {

      puVar12 = puVar11;

    }

    break;

  case 6:

    uVar9 = 0x10;

    puVar5 = (undefined4 *)FUN_14017b8d0(param_5,0,0,8);

    if (puVar5 != (undefined4 *)0x0) goto LAB_1401f38bc;

LAB_1401f393c:

    FUN_14012e850("Unsupported YUV colorspace");

    goto switchD_1401f37a0_default;

  case 7:

    cVar2 = FUN_140142940("SDL_RENDER_OPENGL_NV12_RG_SHADER",0);

    puVar5 = (undefined4 *)FUN_14017b8d0(param_5,0,0,8);

    if (puVar5 == (undefined4 *)0x0) goto LAB_1401f393c;

    uVar9 = (ulonglong)((cVar2 != '\0') + 0x11);

    goto LAB_1401f38bc;

  case 8:

    cVar2 = FUN_140142940("SDL_RENDER_OPENGL_NV12_RG_SHADER",0);

    puVar5 = (undefined4 *)FUN_14017b8d0(param_5,0,0,8);

    if (puVar5 == (undefined4 *)0x0) goto LAB_1401f393c;

    uVar9 = (ulonglong)((cVar2 != '\0') + 0x13);

LAB_1401f38bc:

    puVar12 = (undefined4 *)0x40;

    break;

  case 9:

    uVar9 = 0x15;

    break;

  default:

    goto switchD_1401f37a0_default;

  }

  local_res18 = *(uint *)(param_1 + 0x1e4);

  if (local_res18 == 0) {

    bVar3 = FUN_1401f06c0(param_1,0,0x8b31);

    local_res18 = (uint)bVar3;

    if (local_res18 != 0) goto LAB_1401f39a3;

switchD_1401f37a0_default:

    *(undefined8 *)(param_1 + 0x2c0) = 0;

    uVar8 = 0;

  }

  else {

LAB_1401f39a3:

    uVar10 = *(uint *)(param_1 + 0x1e4 + uVar9 * 4);

    if (uVar10 == 0) {

      bVar3 = FUN_1401f06c0(param_1,uVar9,0x8b30);

      uVar10 = (uint)bVar3;

      if (bVar3 == 0) goto switchD_1401f37a0_default;

    }

    lVar7 = *(longlong *)(param_1 + 0x2c0);

    if ((((lVar7 == 0) || (*(uint *)(lVar7 + 4) != local_res18)) || (*(uint *)(lVar7 + 8) != uVar10)

        ) || ((puVar5 != (undefined4 *)0x0 &&

              ((*(void **)(lVar7 + 0x70) == (void *)0x0 ||

               (iVar4 = memcmp(puVar5,*(void **)(lVar7 + 0x70),(size_t)puVar12), iVar4 != 0)))))) {

      puVar6 = (undefined4 *)FUN_1401f0390(param_1,local_res18,uVar10);

      if (puVar6 == (undefined4 *)0x0) goto switchD_1401f37a0_default;

      (**(code **)(param_1 + 0x168))(*puVar6);

      if ((puVar5 != (undefined4 *)0x0) &&

         ((*(void **)(puVar6 + 0x1c) == (void *)0x0 ||

          (iVar4 = memcmp(puVar5,*(void **)(puVar6 + 0x1c),(size_t)puVar12), iVar4 != 0)))) {

        if ((uint)uVar9 < 0x10) {

          (**(code **)(param_1 + 0x150))(puVar6[8],*puVar5,puVar5[1],puVar5[2],puVar5[3]);

        }

        else {

          if (puVar6[9] != -1) {

            (**(code **)(param_1 + 0x148))(puVar6[9],*puVar5,puVar5[1],puVar5[2]);

          }

          if (puVar6[10] != -1) {

            local_58 = puVar5[4];

            local_54 = puVar5[5];

            local_50 = puVar5[6];

            local_48 = puVar5[9];

            local_4c = puVar5[8];

            local_40 = puVar5[0xc];

            local_44 = puVar5[10];

            local_38 = puVar5[0xe];

            local_3c = puVar5[0xd];

            (**(code **)(param_1 + 0x158))(puVar6[10],1,0,&local_58);

          }

        }

        lVar7 = *(longlong *)(puVar6 + 0x1c);

        if (lVar7 == 0) {

          lVar7 = FUN_1401841f0(puVar12);

          *(longlong *)(puVar6 + 0x1c) = lVar7;

          if (lVar7 == 0) goto LAB_1401f3b5b;

        }

        FUN_1402f8e20(lVar7,puVar5,puVar12);

      }

LAB_1401f3b5b:

      *(undefined4 **)(param_1 + 0x2c0) = puVar6;

    }

    uVar8 = 1;

  }

  return uVar8;

}




