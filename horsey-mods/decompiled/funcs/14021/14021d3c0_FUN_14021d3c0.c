// Address: 0x14021d3c0
// Ghidra name: FUN_14021d3c0
// ============ 0x14021d3c0 FUN_14021d3c0 (size=1042) ============


undefined8 FUN_14021d3c0(longlong param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  longlong lVar7;

  undefined8 uVar8;

  

  iVar1 = *(int *)(param_1 + 0x40);

  uVar6 = *(uint *)(param_2 + 4);

  iVar2 = *(int *)(param_2 + 0x40);

  if (((uVar6 == 0) || ((uVar6 & 0xf0000000) != 0x10000000)) || ((uVar6 & 0xff00) < 0x800))

  goto LAB_14021d704;

  *(code **)(param_1 + 0x80) = FUN_14021d910;

  *(longlong *)(param_1 + 0x90) = param_1;

  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_1 + 0x38);

  *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_1 + 0x48);

  *(longlong *)(param_1 + 0xb8) = param_2;

  *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(param_2 + 0x38);

  *(undefined8 *)(param_1 + 0xf0) = *(undefined8 *)(param_2 + 0x48);

  if (((*(uint *)(param_1 + 0x108) & 0x1000) != 0) &&

     (cVar3 = FUN_1401d2940(param_1), cVar3 != '\0')) {

    return 1;

  }

  if ((iVar1 != iVar2) ||

     ((((uVar6 = *(uint *)(param_1 + 4), uVar6 != 0 && ((uVar6 & 0xf0000000) == 0x10000000)) &&

       (4 < (byte)uVar6)) ||

      (((uVar6 = *(uint *)(param_2 + 4), uVar6 != 0 && ((uVar6 & 0xf0000000) == 0x10000000)) &&

       (4 < (byte)uVar6)))))) {

    *(code **)(param_1 + 0x88) = FUN_1402a1620;

    return 1;

  }

  if ((*(int *)(param_1 + 0x78) != 0) && ((*(uint *)(param_1 + 0x108) & 0xffffefff) == 0)) {

    *(code **)(param_1 + 0x88) = FUN_14029fb60;

    return 0x14029fb01;

  }

  uVar6 = *(uint *)(param_1 + 4);

  if (((uVar6 != 0) && ((uVar6 & 0xf0000000) == 0x10000000)) &&

     (((uVar6 & 0xf000000) == 0x6000000 && ((uVar6 & 0xf0000) == 0x70000)))) goto LAB_14021d55b;

  uVar4 = *(uint *)(param_2 + 4);

  if ((((uVar4 == 0) || ((uVar4 & 0xf0000000) == 0x10000000)) && ((uVar4 & 0xf000000) == 0x6000000))

     && ((uVar4 & 0xf0000) == 0x70000)) goto LAB_14021d55b;

  if ((uVar6 == 0) || ((uVar6 & 0xf0000000) == 0x10000000)) {

    uVar6 = *(uint *)(param_1 + 4);

    if ((uVar6 & 0xff00) < 0x800) {

      uVar6 = *(uint *)(param_1 + 4);

      if (uVar6 != 0) goto LAB_14021d5a6;

      goto LAB_14021d5b4;

    }

LAB_14021d5df:

    if ((((uVar6 == 0) || ((uVar6 & 0xf0000000) != 0x10000000)) || ((char)uVar6 != '\x01')) ||

       (((uVar6 = uVar6 & 0xf000000, uVar6 != 0x1000000 && (uVar6 != 0xc000000)) &&

        ((uVar6 != 0x2000000 && (uVar6 != 0x3000000)))))) {

      if ((*(byte *)(param_1 + 0x108) & 0x10) == 0) {

        lVar7 = FUN_140298870(param_1);

      }

      else {

        lVar7 = FUN_14029f870();

      }

    }

    else {

      lVar7 = FUN_140293220(param_1);

    }

  }

  else {

    uVar6 = *(uint *)(param_1 + 4);

LAB_14021d5a6:

    if ((uVar6 & 0xf0000000) != 0x10000000) goto LAB_14021d5df;

LAB_14021d5b4:

    uVar4 = uVar6 & 0xf000000;

    if (((uVar4 != 0x1000000) && (uVar4 != 0xc000000)) &&

       ((uVar4 != 0x2000000 && (uVar4 != 0x3000000)))) goto LAB_14021d5df;

    lVar7 = FUN_140290640(param_1);

  }

  if ((lVar7 == 0) &&

     (lVar7 = FUN_14021d7e0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_2 + 4),

                            *(undefined4 *)(param_1 + 0x108),&DAT_1403e7a70), lVar7 == 0)) {

    uVar6 = *(uint *)(param_1 + 4);

    uVar4 = *(uint *)(param_2 + 4);

    if (uVar6 == 0) {

      uVar5 = 0;

LAB_14021d739:

      if (((uVar5 == 0xc000000) || (uVar5 == 0x2000000)) || (uVar5 == 0x3000000)) {

LAB_14021d6a5:

        if ((uVar6 != 0x13000801) || (*(longlong *)(param_1 + 0x48) == 0)) goto LAB_14021d6f4;

      }

      else if (uVar6 != 0) goto LAB_14021d763;

LAB_14021d6b5:

      if (uVar4 == 0) {

        uVar6 = 0;

LAB_14021d77d:

        if (((uVar6 != 0xc000000) && (uVar6 != 0x2000000)) && (uVar6 != 0x3000000)) {

          if (uVar4 == 0) goto LAB_14021d55b;

LAB_14021d7a6:

          if ((uVar4 & 0xf0000000) == 0x10000000) goto LAB_14021d55b;

          goto LAB_14021d6f4;

        }

      }

      else {

        if ((uVar4 & 0xf0000000) != 0x10000000) goto LAB_14021d7a6;

        uVar6 = uVar4 & 0xf000000;

        if (uVar6 != 0x1000000) goto LAB_14021d77d;

      }

      if ((uVar4 == 0x13000801) && (*(longlong *)(param_2 + 0x48) != 0)) {

LAB_14021d55b:

        *(code **)(param_1 + 0x88) = FUN_1402a05f0;

        return 0x1402a0501;

      }

    }

    else {

      if ((uVar6 & 0xf0000000) == 0x10000000) {

        uVar5 = uVar6 & 0xf000000;

        if (uVar5 != 0x1000000) goto LAB_14021d739;

        goto LAB_14021d6a5;

      }

LAB_14021d763:

      if ((uVar6 & 0xf0000000) == 0x10000000) goto LAB_14021d6b5;

    }

  }

LAB_14021d6f4:

  *(longlong *)(param_1 + 0x88) = lVar7;

  if (lVar7 != 0) {

    return 1;

  }

LAB_14021d704:

  FUN_14017ba60(param_1 + 0x78);

  uVar8 = FUN_14012e850("Blit combination not supported");

  return uVar8;

}




