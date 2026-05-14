// Address: 0x1401ea3b0
// Ghidra name: FUN_1401ea3b0
// ============ 0x1401ea3b0 FUN_1401ea3b0 (size=703) ============


ulonglong FUN_1401ea3b0(longlong param_1,int *param_2,int *param_3,longlong param_4,int param_5)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  int iVar4;

  ulonglong uVar5;

  longlong lVar6;

  uint uVar7;

  longlong lVar8;

  longlong local_res10;

  undefined8 *local_48;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar5 = FUN_14012e850("Texture is not currently available");

    return uVar5;

  }

  uVar5 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 8),0,*param_3,param_3[1],param_3[2],param_3[3]

                        ,param_4,param_5,lVar1 + 0x18);

  if ((char)uVar5 == '\0') goto LAB_1401ea64e;

  if (*(char *)(lVar1 + 0x50) != '\0') {

    param_4 = param_4 + param_3[3] * param_5;

    local_res10 = lVar1 + 0x68;

    local_48 = (undefined8 *)(lVar1 + 0x58);

    iVar3 = (int)(param_5 + 1U) / 2;

    lVar8 = 0x88;

    if (*param_2 != 0x32315659) {

      lVar8 = 0x68;

    }

    lVar6 = 0x78;

    if (*param_2 != 0x32315659) {

      lVar6 = 0x58;

    }

    uVar5 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar6 + lVar1),0,*param_3 / 2,param_3[1] / 2,

                          (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_4,iVar3,lVar8 + lVar1);

    if ((char)uVar5 == '\0') goto LAB_1401ea64e;

    iVar4 = (param_3[3] + 1) / 2;

    param_4 = param_4 + iVar4 * iVar3;

    if (*param_2 != 0x32315659) {

      local_res10 = lVar1 + 0x88;

      local_48 = (undefined8 *)(lVar1 + 0x78);

    }

    uVar5 = FUN_1401ea670(lVar2,*local_48,0,*param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,iVar4,

                          param_4,iVar3,local_res10);

    if ((char)uVar5 == '\0') goto LAB_1401ea64e;

  }

  if (*(char *)(lVar1 + 0x98) != '\0') {

    if (*param_2 == 0x30313050) {

      uVar7 = param_5 + 3U & 0xfffffffc;

    }

    else {

      uVar7 = param_5 + 1U & 0xfffffffe;

    }

    uVar5 = FUN_1401ea670(lVar2,*(undefined8 *)(lVar1 + 8),1,*param_3,param_3[1],

                          param_3[2] + 1U & 0xfffffffe,param_3[3] + 1U & 0xfffffffe,

                          param_4 + param_3[3] * param_5,uVar7,lVar1 + 0x18);

    if ((char)uVar5 == '\0') {

LAB_1401ea64e:

      return uVar5 & 0xffffffffffffff00;

    }

  }

  lVar8 = *(longlong *)(lVar2 + 0x422c8);

  if (*(longlong *)(lVar1 + 0x10) == lVar8) {

    *(undefined8 *)(lVar2 + 0x422c8) = 0;

  }

  return CONCAT71((int7)((ulonglong)lVar8 >> 8),1);

}




