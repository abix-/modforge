// Address: 0x140143df0
// Ghidra name: FUN_140143df0
// ============ 0x140143df0 FUN_140143df0 (size=1344) ============


ulonglong FUN_140143df0(longlong param_1,undefined8 *param_2,longlong param_3,longlong param_4,

                       uint param_5)



{

  byte bVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  undefined8 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  uint uVar8;

  undefined1 local_res10 [8];

  undefined4 uVar9;

  undefined1 local_58;

  undefined1 local_57;

  undefined1 local_56 [2];

  undefined4 local_54;

  undefined8 local_50;

  undefined4 local_48;

  undefined4 local_44;

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  

  if ((((0xffff < *(int *)(param_2 + 1)) || (0xffff < *(int *)((longlong)param_2 + 0xc))) ||

      (0xffff < *(int *)(param_4 + 8))) || (0xffff < *(int *)(param_4 + 0xc))) {

    uVar7 = FUN_14012e850("Size too large for scaling");

    return uVar7;

  }

  if ((*(uint *)(param_1 + 0x108) >> 0xb & 1) == 0) {

    *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) | 0x800;

    FUN_14017ba60(param_1 + 0x78);

  }

  if ((param_5 & 0xfffffffd) == 0) {

    if (((*(uint *)(param_1 + 0x108) & 0x7f3) == 0) &&

       (uVar8 = *(uint *)(param_1 + 4), uVar8 == *(uint *)(param_3 + 4))) {

      uVar3 = (int)uVar8 >> 0x1c & 0xf;

      if (uVar8 == 0) {

LAB_140144227:

        uVar4 = uVar8 & 0xf000000;

        if (((uVar4 == 0xc000000) || (uVar4 == 0x2000000)) || (uVar4 == 0x3000000)) {

          if ((uVar8 != 0) && (uVar3 == 1)) goto LAB_140144248;

          goto LAB_14014429d;

        }

      }

      else if (uVar3 == 1) {

        if ((uVar8 & 0xf000000) != 0x1000000) goto LAB_140144227;

LAB_140144248:

        if (((uVar8 & 0xff00) != 0x800) ||

           (cVar2 = FUN_14017bac0(*(undefined8 *)(param_1 + 0x48),*(undefined8 *)(param_3 + 0x48)),

           cVar2 == '\0')) goto LAB_14014429d;

      }

      uVar8 = *(uint *)(param_1 + 4);

      if (((uVar8 == 0) || ((uVar8 & 0xf0000000) != 0x10000000)) || ((byte)uVar8 < 5)) {

        uVar9 = 0;

        goto LAB_140144287;

      }

    }

LAB_14014429d:

    uVar8 = *(uint *)(param_1 + 4);

    if (((uVar8 == 0) || ((uVar8 & 0xf0000000) != 0x10000000)) || ((uVar8 & 0xff00) < 0x800)) {

      uVar7 = 0;

      lVar6 = FUN_140145bb0(param_1,0x16362004);

      if (lVar6 != 0) {

        bVar1 = FUN_140143df0(lVar6,param_2,param_3,param_4,0);

        uVar7 = (ulonglong)bVar1;

        FUN_140146010(lVar6);

      }

    }

    else {

      uVar7 = FUN_140144330(param_1,param_2,param_3,param_4);

    }

  }

  else {

    if ((((*(uint *)(param_1 + 0x108) & 0x7f3) != 0) ||

        (uVar8 = *(uint *)(param_1 + 4), uVar8 != *(uint *)(param_3 + 4))) ||

       ((((uVar8 == 0 || ((uVar8 & 0xf0000000) == 0x10000000)) &&

         ((((uVar3 = uVar8 & 0xf000000, uVar3 == 0x1000000 || (uVar3 == 0xc000000)) ||

           (uVar3 == 0x2000000)) || (uVar3 == 0x3000000)))) ||

        (((uVar8 != 0 && ((uVar8 & 0xf0000000) != 0x10000000)) ||

         (((char)*(int *)(param_1 + 4) != '\x04' || (*(int *)(param_1 + 4) == 0x16372004)))))))) {

      uVar8 = *(uint *)(param_1 + 4);

      if (((uVar8 == 0) || ((uVar8 & 0xf0000000) != 0x10000000)) || ((uVar8 & 0xff00) < 0x800)) {

        lVar6 = FUN_140145bb0(param_1,0x16362004);

        if (lVar6 == 0) {

          return 0;

        }

        bVar1 = FUN_140143df0(lVar6,param_2,param_3,param_4,param_5);

        FUN_140146010(lVar6);

        return (ulonglong)bVar1;

      }

      uVar3 = *(uint *)(param_1 + 0x108) & 0x7f3;

      FUN_1401467d0(param_1,&local_57,&local_58,local_res10);

      FUN_140146570(param_1,local_56);

      FUN_1401465d0(param_1,&local_54);

      uVar8 = *(uint *)(param_1 + 4);

      local_50 = *param_2;

      local_48 = *(undefined4 *)(param_2 + 1);

      local_44 = *(undefined4 *)((longlong)param_2 + 0xc);

      if ((((uVar8 == 0) || ((uVar8 & 0xf0000000) != 0x10000000)) || ((char)uVar8 != '\x04')) ||

         (lVar6 = 0, uVar8 == 0x16372004)) {

        uVar8 = *(uint *)(param_3 + 4);

        if ((((uVar8 == 0) || ((uVar8 & 0xf0000000) != 0x10000000)) ||

            (((char)uVar8 != '\x04' || (uVar8 == 0x16372004)))) ||

           ((((((uVar4 = uVar8 & 0xf000000, uVar4 != 0x4000000 && (uVar4 != 0x5000000)) &&

               (uVar4 != 0x6000000)) ||

              ((((uVar4 = uVar8 & 0xf00000, uVar4 != 0x300000 && (uVar4 != 0x400000)) &&

                (uVar4 != 0x700000)) && (uVar4 != 0x800000)))) &&

             ((((uVar8 & 0xf0000000) != 0x10000000 ||

               (((uVar8 & 0xf000000) != 0x7000000 &&

                (((uVar8 & 0xf000000) + 0xf8000000 & 0xfcffffff) != 0)))) ||

              ((uVar8 = uVar8 & 0xf00000, uVar8 != 0x300000 &&

               (((uVar8 != 0x200000 && (uVar8 != 0x600000)) && (uVar8 != 0x500000)))))))) &&

            (uVar3 != 0)))) {

          uVar9 = 0x16362004;

        }

        else {

          uVar9 = *(undefined4 *)(param_3 + 4);

        }

        param_1 = FUN_140145250(param_1,param_2,uVar9);

        if (param_1 == 0) {

          return 0;

        }

        local_50 = 0;

        lVar6 = param_1;

      }

      if ((uVar3 == 0) && (*(int *)(param_1 + 4) == *(int *)(param_3 + 4))) {

        bVar1 = FUN_140199be0(param_1,&local_50,param_3,param_4,1);

        FUN_140146010(lVar6);

        return (ulonglong)bVar1;

      }

      uVar5 = FUN_140145e60(*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc),

                            *(undefined4 *)(param_1 + 4));

      FUN_140199be0(param_1,&local_50,uVar5,0,1);

      FUN_1401486f0(uVar5,local_57,local_58,local_res10[0]);

      FUN_1401483d0(uVar5,local_56[0]);

      FUN_140148450(uVar5,local_54);

      local_38 = *(undefined4 *)(param_4 + 8);

      local_34 = *(undefined4 *)(param_4 + 0xc);

      local_40 = 0;

      bVar1 = FUN_140144330(uVar5,&local_40,param_3,param_4);

      FUN_140146010(uVar5);

      FUN_140146010(lVar6);

      return (ulonglong)bVar1;

    }

    uVar9 = 1;

LAB_140144287:

    uVar7 = FUN_140199be0(param_1,param_2,param_3,param_4,uVar9);

  }

  return uVar7;

}




