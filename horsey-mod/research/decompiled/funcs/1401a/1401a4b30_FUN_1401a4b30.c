// Address: 0x1401a4b30
// Ghidra name: FUN_1401a4b30
// ============ 0x1401a4b30 FUN_1401a4b30 (size=271) ============


char FUN_1401a4b30(longlong *param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  char *pcVar4;

  

LAB_1401a4b40:

  lVar2 = *param_1;

  if (*(longlong *)(lVar2 + 0x10) == 0) {

LAB_1401a4b62:

    if (*(ulonglong *)(lVar2 + 200) <= *(ulonglong *)(lVar2 + 0xc0)) {

      return -1;

    }

  }

  else {

    iVar3 = (**(code **)(lVar2 + 0x20))(*(undefined8 *)(lVar2 + 0x28));

    if (iVar3 != 0) {

      if (*(int *)(lVar2 + 0x30) == 0) {

        return -1;

      }

      goto LAB_1401a4b62;

    }

  }

  lVar2 = *param_1;

  pcVar4 = *(char **)(lVar2 + 0xc0);

  if (*(char **)(lVar2 + 200) <= pcVar4) goto code_r0x0001401a4b89;

  goto LAB_1401a4b9e;

code_r0x0001401a4b89:

  if (*(int *)(lVar2 + 0x30) != 0) {

    FUN_1401a4400(lVar2);

    pcVar4 = *(char **)(lVar2 + 0xc0);

LAB_1401a4b9e:

    cVar1 = *pcVar4;

    *(char **)(lVar2 + 0xc0) = pcVar4 + 1;

    if (cVar1 == -1) {

      do {

        lVar2 = *param_1;

        if (*(longlong *)(lVar2 + 0x10) == 0) {

LAB_1401a4bce:

          if (*(ulonglong *)(lVar2 + 200) <= *(ulonglong *)(lVar2 + 0xc0)) {

            return -1;

          }

        }

        else {

          iVar3 = (**(code **)(lVar2 + 0x20))(*(undefined8 *)(lVar2 + 0x28));

          if (iVar3 != 0) {

            if (*(int *)(lVar2 + 0x30) == 0) {

              return -1;

            }

            goto LAB_1401a4bce;

          }

        }

        lVar2 = *param_1;

        pcVar4 = *(char **)(lVar2 + 0xc0);

        if (*(char **)(lVar2 + 200) <= pcVar4) {

          if (*(int *)(lVar2 + 0x30) == 0) break;

          FUN_1401a4400(lVar2);

          pcVar4 = *(char **)(lVar2 + 0xc0);

        }

        cVar1 = *pcVar4;

        *(char **)(lVar2 + 0xc0) = pcVar4 + 1;

        if (cVar1 == '\0') break;

        if (cVar1 != -1) {

          return cVar1;

        }

      } while( true );

    }

  }

  goto LAB_1401a4b40;

}




