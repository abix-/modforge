// Address: 0x140147b80
// Ghidra name: FUN_140147b80
// ============ 0x140147b80 FUN_140147b80 (size=716) ============


ulonglong FUN_140147b80(byte *param_1,int param_2,int param_3,undefined1 *param_4,

                       undefined1 *param_5,undefined1 *param_6,undefined1 *param_7)



{

  char cVar1;

  byte bVar2;

  uint uVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  longlong lVar6;

  char *pcVar7;

  undefined1 *puVar8;

  undefined1 *puVar9;

  undefined1 *puVar10;

  undefined1 local_res20 [8];

  undefined8 in_stack_ffffffffffffff78;

  undefined4 uVar11;

  undefined8 in_stack_ffffffffffffff88;

  undefined4 uVar12;

  undefined4 local_48 [4];

  

  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);

  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);

  bVar2 = 0;

  local_48[0] = 0;

  if (param_4 == (undefined1 *)0x0) {

    param_4 = local_res20;

  }

  else {

    *param_4 = 0;

  }

  if (param_5 == (undefined1 *)0x0) {

    puVar9 = local_res20;

  }

  else {

    *param_5 = 0;

    puVar9 = param_5;

  }

  if (param_6 == (undefined1 *)0x0) {

    puVar8 = local_res20;

  }

  else {

    *param_6 = 0;

    puVar8 = param_6;

  }

  if (param_7 == (undefined1 *)0x0) {

    puVar10 = local_res20;

  }

  else {

    *param_7 = 0;

    puVar10 = param_7;

  }

  cVar1 = FUN_1401489c0();

  if (((cVar1 == '\0') || (uVar3 = *(uint *)(param_1 + 4), uVar3 == 0)) ||

     (*(longlong *)(param_1 + 0x18) == 0)) {

    pcVar7 = "surface";

LAB_140147e28:

    uVar5 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar7);

    return uVar5;

  }

  if ((param_2 < 0) || (*(int *)(param_1 + 8) <= param_2)) {

    pcVar7 = "x";

    goto LAB_140147e28;

  }

  if ((param_3 < 0) || (*(int *)(param_1 + 0xc) <= param_3)) {

    pcVar7 = "y";

    goto LAB_140147e28;

  }

  if ((uVar3 & 0xf0000000) == 0x10000000) {

    uVar3 = uVar3 & 0xff;

  }

  else if ((((uVar3 == 0x32595559) || (uVar3 == 0x59565955)) || (uVar3 == 0x55595659)) ||

          (uVar3 == 0x30313050)) {

    uVar3 = 2;

  }

  else {

    uVar3 = 1;

  }

  uVar5 = (ulonglong)uVar3;

  if (((*param_1 & 2) != 0) && (uVar4 = FUN_140146f20(param_1), (char)uVar4 == '\0')) {

    return uVar4;

  }

  lVar6 = (longlong)param_2 * uVar5 + (longlong)(*(int *)(param_1 + 0x10) * param_3) +

          *(longlong *)(param_1 + 0x18);

  if ((uVar5 < 5) &&

     ((*(uint *)(param_1 + 4) == 0 || ((*(uint *)(param_1 + 4) & 0xf0000000) == 0x10000000)))) {

    FUN_1402f8e20(local_48,lVar6,uVar5);

    FUN_14017b4a0(local_48[0],*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x48),

                  param_4,puVar9,puVar8,puVar10);

  }

  else {

    uVar3 = *(uint *)(param_1 + 4);

    if ((uVar3 != 0) && ((uVar3 & 0xf0000000) != 0x10000000)) {

      lVar6 = FUN_140145bb0(param_1,0x16362004);

      if (lVar6 != 0) {

        bVar2 = FUN_140147b80(lVar6,param_2,param_3,param_4,puVar9,puVar8,puVar10);

        FUN_140146010(lVar6);

      }

      goto LAB_140147dfc;

    }

    cVar1 = FUN_140144d60(1,1,uVar3,*(undefined4 *)(param_1 + 0x40),

                          CONCAT44(uVar11,*(undefined4 *)(param_1 + 0x34)),lVar6,

                          CONCAT44(uVar12,*(int *)(param_1 + 0x10)),0x16762004,0x120005a0,0,&param_5

                          ,4);

    if (cVar1 == '\0') goto LAB_140147dfc;

    *param_4 = param_5._0_1_;

    *puVar9 = param_5._1_1_;

    *puVar8 = param_5._2_1_;

    *puVar10 = param_5._3_1_;

  }

  bVar2 = 1;

LAB_140147dfc:

  if ((*param_1 & 2) != 0) {

    FUN_1401489e0(param_1);

  }

  return (ulonglong)bVar2;

}




