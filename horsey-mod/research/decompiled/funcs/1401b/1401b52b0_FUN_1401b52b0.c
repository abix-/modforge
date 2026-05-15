// Address: 0x1401b52b0
// Ghidra name: FUN_1401b52b0
// ============ 0x1401b52b0 FUN_1401b52b0 (size=517) ============


undefined8

FUN_1401b52b0(undefined8 *param_1,uint param_2,undefined1 *param_3,undefined1 *param_4,

             undefined1 *param_5,undefined1 *param_6,uint *param_7)



{

  char *_Str1;

  undefined1 uVar1;

  int iVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  ulonglong uVar6;

  uint uVar7;

  undefined8 uVar8;

  uint uVar9;

  uint local_res10 [2];

  undefined1 *local_res18;

  undefined1 *local_res20;

  

  local_res18 = param_3;

  local_res20 = param_4;

  (*DAT_1403fce20)(0,local_res10,0);

  lVar3 = FUN_1401841f0((ulonglong)local_res10[0] * 0x104);

  (*DAT_1403fce20)(0,local_res10,lVar3);

  uVar7 = 0;

  uVar9 = 0;

  if (param_2 != 0) {

    do {

      uVar5 = local_res10[0];

      uVar6 = 0;

      _Str1 = (char *)*param_1;

      if (local_res10[0] == 0) {

LAB_1401b534e:

        uVar8 = 0;

        *param_7 = uVar9;

        param_3 = local_res18;

        goto LAB_1401b5377;

      }

      while( true ) {

        iVar2 = strcmp(_Str1,(char *)(uVar6 * 0x104 + lVar3));

        if (iVar2 == 0) break;

        uVar4 = (int)uVar6 + 1;

        uVar6 = (ulonglong)uVar4;

        if (uVar5 <= uVar4) goto LAB_1401b534e;

      }

      uVar9 = uVar9 + 1;

      param_1 = param_1 + 1;

      param_3 = local_res18;

    } while (uVar9 < param_2);

  }

  uVar8 = 1;

LAB_1401b5377:

  uVar9 = local_res10[0];

  uVar6 = 0;

  if (local_res10[0] != 0) {

    do {

      iVar2 = strcmp("VK_EXT_debug_utils",(char *)(uVar6 * 0x104 + lVar3));

      if (iVar2 == 0) {

        uVar1 = 1;

        goto LAB_1401b53b8;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < uVar9);

  }

  uVar1 = 0;

LAB_1401b53b8:

  uVar9 = local_res10[0];

  uVar5 = 0;

  *param_3 = uVar1;

  if (local_res10[0] != 0) {

    do {

      iVar2 = strcmp("VK_EXT_swapchain_colorspace",(char *)((ulonglong)uVar5 * 0x104 + lVar3));

      if (iVar2 == 0) {

        uVar1 = 1;

        goto LAB_1401b53f8;

      }

      uVar5 = uVar5 + 1;

    } while (uVar5 < uVar9);

  }

  uVar1 = 0;

LAB_1401b53f8:

  uVar9 = local_res10[0];

  uVar6 = 0;

  *local_res20 = uVar1;

  if (local_res10[0] != 0) {

    do {

      iVar2 = strcmp("VK_KHR_get_physical_device_properties2",(char *)(uVar6 * 0x104 + lVar3));

      if (iVar2 == 0) {

        uVar1 = 1;

        goto LAB_1401b5438;

      }

      uVar5 = (int)uVar6 + 1;

      uVar6 = (ulonglong)uVar5;

    } while (uVar5 < uVar9);

  }

  uVar1 = 0;

LAB_1401b5438:

  *param_5 = uVar1;

  if (local_res10[0] != 0) {

    do {

      iVar2 = strcmp("VK_KHR_portability_enumeration",(char *)((ulonglong)uVar7 * 0x104 + lVar3));

      if (iVar2 == 0) {

        uVar1 = 1;

        goto LAB_1401b5474;

      }

      uVar7 = uVar7 + 1;

    } while (uVar7 < local_res10[0]);

  }

  uVar1 = 0;

LAB_1401b5474:

  *param_6 = uVar1;

  FUN_1401841e0(lVar3);

  return uVar8;

}




