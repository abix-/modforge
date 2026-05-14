// Address: 0x14016a780
// Ghidra name: FUN_14016a780
// ============ 0x14016a780 FUN_14016a780 (size=327) ============


longlong FUN_14016a780(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  undefined4 local_res10 [2];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  undefined4 *puVar3;

  undefined4 local_18 [2];

  undefined8 local_10;

  undefined4 uVar4;

  

  local_res18[0] = 0;

  local_10 = 0;

  local_res10[0] = 0;

  FUN_14016ebe0(param_1,local_18,local_res20);

  lVar2 = DAT_1403fc410;

  if (*(char *)(DAT_1403fc410 + 0x318) == '\0') {

    cVar1 = FUN_140174280();

    if (cVar1 == '\0') {

LAB_14016a841:

      lVar2 = DAT_1403fc410;

      *(undefined1 *)(DAT_1403fc410 + 0x318) = 1;

      goto LAB_14016a84f;

    }

    puVar3 = local_res10;

    cVar1 = FUN_14016a8d0(DAT_1403fc410,param_1,local_res18,&local_10,puVar3);

    lVar2 = DAT_1403fc410;

    uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);

    if (cVar1 == '\0') goto LAB_14016a841;

    *(code **)(DAT_1403fc410 + 0x138) = FUN_14016a8d0;

    *(code **)(lVar2 + 0x140) = FUN_1401723f0;

    *(code **)(lVar2 + 0x148) = FUN_14016ef40;

    *(code **)(lVar2 + 0x150) = FUN_140173930;

    *(code **)(lVar2 + 0x158) = FUN_14016b6a0;

    *(undefined1 *)(lVar2 + 0x318) = 1;

LAB_14016a882:

    lVar2 = *(longlong *)(param_1 + 0x100);

    if (lVar2 == 0) {

      lVar2 = FUN_140145bc0(local_18[0],local_res20[0],local_res18[0],local_10,

                            CONCAT44(uVar4,local_res10[0]));

      return lVar2;

    }

  }

  else {

LAB_14016a84f:

    if ((*(code **)(lVar2 + 0x138) == (code *)0x0) || (*(longlong *)(lVar2 + 0x150) == 0)) {

      FUN_14012e850("Window framebuffer support not available");

    }

    else {

      puVar3 = local_res10;

      cVar1 = (**(code **)(lVar2 + 0x138))(lVar2,param_1,local_res18,&local_10,puVar3);

      uVar4 = (undefined4)((ulonglong)puVar3 >> 0x20);

      if (cVar1 != '\0') goto LAB_14016a882;

    }

    lVar2 = 0;

  }

  return lVar2;

}




