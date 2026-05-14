// Address: 0x1401735a0
// Ghidra name: FUN_1401735a0
// ============ 0x1401735a0 FUN_1401735a0 (size=381) ============


void FUN_1401735a0(longlong param_1)



{

  ulonglong uVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  ulonglong *puVar5;

  bool bVar6;

  

  if ((*(uint *)(param_1 + 0x48) >> 9 & 1) == 0) {

    cVar2 = '\0';

    bVar6 = false;

  }

  else {

    lVar3 = FUN_1401611a0();

    lVar4 = DAT_1403fc410;

    if ((*(char *)(lVar3 + 0xc1) == '\0') && ((*(uint *)(param_1 + 0x48) >> 8 & 1) == 0)) {

      cVar2 = '\0';

    }

    else {

      cVar2 = '\x01';

    }

    uVar1 = *(ulonglong *)(param_1 + 0x48);

    bVar6 = (uVar1 & 0x100000) != 0;

    if ((cVar2 != '\0') || ((uVar1 & 0x100000) != 0)) {

      lVar3 = *(longlong *)(DAT_1403fc410 + 0x350);

      if ((lVar3 != 0) && (lVar3 != param_1)) {

        *(ulonglong *)(lVar3 + 0x48) = *(ulonglong *)(lVar3 + 0x48) & 0xffffffffffeffeff;

        if (*(code **)(lVar4 + 0x120) != (code *)0x0) {

          (**(code **)(lVar4 + 0x120))(lVar4,*(undefined8 *)(lVar4 + 0x350),0);

          lVar4 = DAT_1403fc410;

        }

        if (*(code **)(lVar4 + 0x128) != (code *)0x0) {

          (**(code **)(lVar4 + 0x128))(lVar4,*(undefined8 *)(lVar4 + 0x350),0);

          lVar4 = DAT_1403fc410;

        }

      }

      *(longlong *)(lVar4 + 0x350) = param_1;

      goto LAB_140173694;

    }

  }

  lVar4 = DAT_1403fc410;

  if (*(longlong *)(DAT_1403fc410 + 0x350) == param_1) {

    *(undefined8 *)(DAT_1403fc410 + 0x350) = 0;

  }

LAB_140173694:

  puVar5 = (ulonglong *)(param_1 + 0x48);

  if ((*(code **)(lVar4 + 0x120) != (code *)0x0) &&

     (cVar2 = (**(code **)(lVar4 + 0x120))(lVar4,param_1,cVar2), lVar4 = DAT_1403fc410,

     cVar2 == '\0')) {

    *puVar5 = *puVar5 & 0xfffffffffffffeff;

  }

  if ((*(code **)(lVar4 + 0x128) != (code *)0x0) &&

     (cVar2 = (**(code **)(lVar4 + 0x128))(lVar4,param_1,bVar6), lVar4 = DAT_1403fc410,

     cVar2 == '\0')) {

    *puVar5 = *puVar5 & 0xffffffffffefffff;

  }

  if ((*(longlong *)(lVar4 + 0x350) != 0) &&

     ((*(uint *)(*(longlong *)(lVar4 + 0x350) + 0x48) & 0x100100) == 0)) {

    *(undefined8 *)(lVar4 + 0x350) = 0;

  }

  return;

}




