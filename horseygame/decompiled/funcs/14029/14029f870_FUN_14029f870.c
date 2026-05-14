// Address: 0x14029f870
// Ghidra name: FUN_14029f870
// ============ 0x14029f870 FUN_14029f870 (size=738) ============


code * FUN_14029f870(longlong param_1)



{

  uint *puVar1;

  uint *puVar2;

  char cVar3;

  uint uVar4;

  code *pcVar5;

  code *pcVar6;

  

  puVar1 = *(uint **)(param_1 + 0x38);

  uVar4 = *(uint *)(param_1 + 0x108) & 0xffff8fff;

  puVar2 = *(uint **)(param_1 + 0xe8);

  if (uVar4 == 0x10) {

    cVar3 = *(char *)((longlong)puVar2 + 5);

    if (cVar3 != '\x01') {

      if (cVar3 == '\x02') {

        if ((((*(char *)((longlong)puVar1 + 5) == '\x04') && (puVar1[5] == 0xff000000)) &&

            (puVar1[3] == 0xff00)) &&

           (((puVar1[2] == 0xff && (puVar2[2] == 0x1f)) ||

            ((puVar1[4] == 0xff && (puVar2[4] == 0x1f)))))) {

          if (puVar2[3] == 0x7e0) {

            return FUN_14029a490;

          }

          if ((puVar2[3] == 0x3e0) && (puVar2[5] == 0)) {

            return FUN_14029a1a0;

          }

        }

      }

      else if ((((cVar3 == '\x04') && ((*puVar1 & 0xf0000) == 0x60000)) && (puVar1[5] != 0)) &&

              ((*puVar2 & 0xf0000) == 0x60000)) {

        cVar3 = FUN_14017fd60();

        if (cVar3 != '\0') {

          return FUN_140299770;

        }

        cVar3 = FUN_14017fe90();

        if (cVar3 != '\0') {

          return FUN_140299ba0;

        }

        pcVar5 = FUN_140299510;

        if (*puVar1 == *puVar2) {

          pcVar5 = FUN_1402993e0;

        }

        return pcVar5;

      }

      return FUN_14029c020;

    }

    pcVar5 = FUN_14029c020;

    pcVar6 = FUN_14029a780;

LAB_14029fb3b:

    if (*(longlong *)(param_1 + 0xf0) != 0) {

      pcVar5 = pcVar6;

    }

    return pcVar5;

  }

  if (uVar4 == 0x12) {

    if (puVar1[5] == 0) {

      cVar3 = *(char *)((longlong)puVar2 + 5);

      if (cVar3 != '\x01') {

        if (cVar3 == '\x02') {

          if (*(int *)(param_1 + 0x78) != 0) {

            if (puVar2[3] == 0x7e0) {

              return FUN_1402991a0;

            }

            if (puVar2[3] == 0x3e0) {

              return FUN_140298f60;

            }

          }

        }

        else if ((((cVar3 != '\x03') && (cVar3 == '\x04')) &&

                 ((puVar1[2] == puVar2[2] && ((puVar1[3] == puVar2[3] && (puVar1[4] == puVar2[4]))))

                 )) && (*(char *)((longlong)puVar1 + 5) == '\x04')) {

          if ((((puVar1[7] & 7) == 0) && ((*(byte *)((longlong)puVar1 + 0x1d) & 7) == 0)) &&

             ((*(byte *)((longlong)puVar1 + 0x1e) & 7) == 0)) {

            cVar3 = FUN_14017fe50();

            if (cVar3 != '\0') {

              return FUN_140299f90;

            }

          }

          if ((puVar1[4] | puVar1[2] | puVar1[3]) == 0xffffff) {

            return FUN_14029f430;

          }

        }

        return FUN_14029d250;

      }

      pcVar5 = FUN_14029d250;

      pcVar6 = FUN_14029afc0;

      goto LAB_14029fb3b;

    }

  }

  else if ((uVar4 == 0x412) && (puVar1[5] == 0)) {

    if ((*(char *)((longlong)puVar2 + 5) == '\x01') && (*(longlong *)(param_1 + 0xf0) != 0)) {

      return FUN_14029b740;

    }

    return FUN_14029e390;

  }

  return (code *)0x0;

}




