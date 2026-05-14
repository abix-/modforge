// Address: 0x1402d6558
// Ghidra name: FUN_1402d6558
// ============ 0x1402d6558 FUN_1402d6558 (size=1397) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



undefined8 FUN_1402d6558(longlong param_1)



{

  int *piVar1;

  string_output_adapter<wchar_t> *this;

  ushort uVar2;

  short sVar3;

  longlong lVar4;

  char cVar5;

  longlong lVar6;

  undefined2 uVar7;

  int iVar8;

  ulonglong uVar9;

  undefined2 uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  uint uVar13;

  int iVar14;

  longlong lVar15;

  int iVar16;

  undefined1 auStackY_88 [32];

  undefined4 local_58;

  undefined8 local_50;

  undefined8 local_48;

  undefined8 local_40;

  ulonglong local_38;

  

  local_48 = 0xfffffffffffffffe;

  local_38 = DAT_1403e8b00 ^ (ulonglong)auStackY_88;

  uVar2 = *(ushort *)(param_1 + 0x3a);

  uVar10 = 0x78;

  uVar12 = 1;

  if (uVar2 < 0x65) {

    if (uVar2 == 100) {

LAB_1402d6639:

      *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x10;

LAB_1402d663d:

      cVar5 = FUN_1402d2e70(param_1,0);

    }

    else if (uVar2 < 0x54) {

      if (uVar2 == 0x53) {

LAB_1402d667d:

        cVar5 = FUN_1402d7384();

      }

      else {

        if (uVar2 != 0x41) {

          if (uVar2 == 0x43) {

LAB_1402d65fc:

            cVar5 = FUN_1402d716c(param_1,0);

            goto LAB_1402d669a;

          }

          if (((uVar2 != 0x45) && (uVar2 != 0x46)) && (uVar2 != 0x47)) {

            return 0;

          }

        }

LAB_1402d65d7:

        cVar5 = FUN_1402d6e1c();

      }

    }

    else {

      if (uVar2 == 0x58) goto LAB_1402d6692;

      if (uVar2 != 0x5a) {

        if (uVar2 != 0x61) {

          if (uVar2 != 99) {

            return 0;

          }

          goto LAB_1402d65fc;

        }

        goto LAB_1402d65d7;

      }

      cVar5 = FUN_1402d6b4c();

    }

  }

  else if (uVar2 < 0x70) {

    if (uVar2 == 0x6f) {

      if ((*(uint *)(param_1 + 0x28) >> 5 & 1) != 0) {

        *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x80;

      }

      cVar5 = FUN_1402d2a60(param_1,0);

    }

    else {

      if (((uVar2 == 0x65) || (uVar2 == 0x66)) || (uVar2 == 0x67)) goto LAB_1402d65d7;

      if (uVar2 == 0x69) goto LAB_1402d6639;

      if (uVar2 != 0x6e) {

        return 0;

      }

      cVar5 = FUN_1402d7230();

    }

  }

  else {

    if (uVar2 == 0x70) {

      *(undefined4 *)(param_1 + 0x30) = 0x10;

      *(undefined4 *)(param_1 + 0x34) = 0xb;

LAB_1402d6692:

      uVar7 = CONCAT11((char)(uVar2 >> 8),1);

    }

    else {

      if (uVar2 == 0x73) goto LAB_1402d667d;

      if (uVar2 == 0x75) goto LAB_1402d663d;

      if (uVar2 != 0x78) {

        return 0;

      }

      uVar7 = 0;

    }

    cVar5 = FUN_1402d3280(param_1,uVar7);

  }

LAB_1402d669a:

  uVar9 = 0;

  if (cVar5 == '\0') {

    return 0;

  }

  if (*(char *)(param_1 + 0x38) != '\0') {

    return 1;

  }

  local_40 = (ulonglong)local_40._6_2_ << 0x30;

  uVar13 = *(uint *)(param_1 + 0x28);

  uVar11 = uVar9;

  if ((uVar13 >> 4 & 1) != 0) {

    if ((uVar13 >> 6 & 1) == 0) {

      if ((*(byte *)(param_1 + 0x28) & 1) == 0) {

        uVar11 = 0;

        if ((uVar13 >> 1 & 1) != 0) {

          local_40 = CONCAT62(local_40._2_6_,0x20);

          uVar11 = uVar12;

        }

        goto LAB_1402d6703;

      }

      uVar7 = 0x2b;

    }

    else {

      uVar7 = 0x2d;

    }

    local_40 = CONCAT62(local_40._2_6_,uVar7);

    uVar11 = uVar12;

  }

LAB_1402d6703:

  sVar3 = *(short *)(param_1 + 0x3a);

  if (((sVar3 - 0x58U & 0xffdf) != 0) || ((uVar13 >> 5 & 1) == 0)) {

    uVar12 = uVar9;

  }

  if (((char)uVar12 != '\0') || ((sVar3 - 0x41U & 0xffdf) == 0)) {

    *(undefined2 *)((longlong)&local_40 + uVar11 * 2) = 0x30;

    if ((sVar3 == 0x58) || (sVar3 == 0x41)) {

      uVar10 = 0x58;

    }

    *(undefined2 *)((longlong)&local_40 + (uVar11 + 1) * 2) = uVar10;

    uVar11 = uVar11 + 2;

  }

  iVar16 = (*(int *)(param_1 + 0x2c) - (int)uVar11) - *(int *)(param_1 + 0x48);

  if (((uVar13 & 0xc) == 0) && (0 < iVar16)) {

    iVar8 = *(int *)(param_1 + 0x20);

    uVar12 = uVar9;

    do {

      lVar6 = *(longlong *)(param_1 + 0x460);

      if (*(longlong *)(lVar6 + 0x10) == *(longlong *)(lVar6 + 8)) {

        if (*(char *)(lVar6 + 0x18) == '\0') {

          iVar8 = -1;

        }

        else {

          iVar8 = iVar8 + 1;

        }

        *(int *)(param_1 + 0x20) = iVar8;

      }

      else {

        *(int *)(param_1 + 0x20) = iVar8 + 1;

        *(longlong *)(lVar6 + 0x10) = *(longlong *)(lVar6 + 0x10) + 1;

        *(undefined2 *)**(undefined8 **)(param_1 + 0x460) = 0x20;

        **(longlong **)(param_1 + 0x460) = **(longlong **)(param_1 + 0x460) + 2;

      }

      iVar8 = *(int *)(param_1 + 0x20);

    } while ((iVar8 != -1) &&

            (uVar13 = (int)uVar12 + 1, uVar12 = (ulonglong)uVar13, (int)uVar13 < iVar16));

  }

  this = (string_output_adapter<wchar_t> *)(param_1 + 0x460);

  piVar1 = (int *)(param_1 + 0x20);

  __crt_stdio_output::string_output_adapter<wchar_t>::write_string

            (this,(wchar_t *)&local_40,(int)uVar11,piVar1,

             *(__crt_deferred_errno_cache **)(param_1 + 8));

  if (((*(uint *)(param_1 + 0x28) >> 3 & 1) != 0) &&

     (((*(uint *)(param_1 + 0x28) >> 2 & 1) == 0 && (0 < iVar16)))) {

    iVar8 = *piVar1;

    uVar12 = uVar9;

    do {

      lVar6 = *(longlong *)this;

      if (*(longlong *)(lVar6 + 0x10) == *(longlong *)(lVar6 + 8)) {

        if (*(char *)(lVar6 + 0x18) == '\0') {

          iVar8 = -1;

        }

        else {

          iVar8 = iVar8 + 1;

        }

        *piVar1 = iVar8;

      }

      else {

        *piVar1 = iVar8 + 1;

        *(longlong *)(lVar6 + 0x10) = *(longlong *)(lVar6 + 0x10) + 1;

        *(undefined2 *)**(undefined8 **)this = 0x30;

        **(longlong **)this = **(longlong **)this + 2;

      }

      iVar8 = *piVar1;

    } while ((iVar8 != -1) &&

            (uVar13 = (int)uVar12 + 1, uVar12 = (ulonglong)uVar13, (int)uVar13 < iVar16));

  }

  if ((*(char *)(param_1 + 0x4c) == '\0') && (0 < *(int *)(param_1 + 0x48))) {

    lVar6 = *(longlong *)(param_1 + 8);

    if (*(char *)(lVar6 + 0x28) == '\0') {

      FUN_1402d74e0(lVar6);

    }

    if (*(int *)(*(longlong *)(lVar6 + 0x18) + 0xc) == 0xfde9) {

      local_50 = *(undefined8 *)(param_1 + 0x40);

      local_40 = 0;

      if (*(int *)(param_1 + 0x48) != 0) {

        do {

          iVar8 = (int)uVar9;

          local_58 = 0;

          lVar6 = FUN_1402f0444(&local_58,&local_50,2,&local_40);

          if (lVar6 == -1) goto LAB_1402d6a01;

          lVar15 = *(longlong *)this;

          if (*(longlong *)(lVar15 + 0x10) == *(longlong *)(lVar15 + 8)) {

            if (*(char *)(lVar15 + 0x18) == '\0') {

              *piVar1 = -1;

            }

            else {

              *piVar1 = *piVar1 + 1;

            }

          }

          else {

            *piVar1 = *piVar1 + 1;

            *(longlong *)(lVar15 + 0x10) = *(longlong *)(lVar15 + 0x10) + 1;

            *(undefined2 *)**(undefined8 **)this = (undefined2)local_58;

            **(longlong **)this = **(longlong **)this + 2;

          }

          if (lVar6 == 2) {

            lVar6 = *(longlong *)this;

            if (*(longlong *)(lVar6 + 0x10) == *(longlong *)(lVar6 + 8)) {

              if (*(char *)(lVar6 + 0x18) == '\0') {

                *piVar1 = -1;

              }

              else {

                *piVar1 = *piVar1 + 1;

              }

            }

            else {

              *piVar1 = *piVar1 + 1;

              *(longlong *)(lVar6 + 0x10) = *(longlong *)(lVar6 + 0x10) + 1;

              *(undefined2 *)**(undefined8 **)this = local_58._2_2_;

              **(longlong **)this = **(longlong **)this + 2;

            }

            iVar8 = iVar8 + 1;

          }

          uVar9 = (ulonglong)(iVar8 + 1U);

        } while (iVar8 + 1U != *(uint *)(param_1 + 0x48));

      }

    }

    else {

      lVar6 = *(longlong *)(param_1 + 8);

      if (*(char *)(lVar6 + 0x28) == '\0') {

        FUN_1402d74e0(lVar6);

      }

      lVar15 = *(longlong *)(param_1 + 0x40);

      iVar8 = 0;

      if (*(int *)(param_1 + 0x48) != 0) {

        do {

          local_58 = local_58 & 0xffff0000;

          iVar14 = FUN_1402eff44(&local_58,lVar15,

                                 (longlong)*(int *)(*(longlong *)(lVar6 + 0x18) + 8));

          if (iVar14 < 1) goto LAB_1402d6a01;

          lVar4 = *(longlong *)this;

          if (*(longlong *)(lVar4 + 0x10) == *(longlong *)(lVar4 + 8)) {

            if (*(char *)(lVar4 + 0x18) == '\0') {

              *piVar1 = -1;

            }

            else {

              *piVar1 = *piVar1 + 1;

            }

          }

          else {

            *piVar1 = *piVar1 + 1;

            *(longlong *)(lVar4 + 0x10) = *(longlong *)(lVar4 + 0x10) + 1;

            *(undefined2 *)**(undefined8 **)this = (undefined2)local_58;

            **(longlong **)this = **(longlong **)this + 2;

          }

          lVar15 = lVar15 + iVar14;

          iVar8 = iVar8 + 1;

        } while (iVar8 != *(int *)(param_1 + 0x48));

      }

    }

  }

  else {

    __crt_stdio_output::string_output_adapter<wchar_t>::write_string

              (this,*(wchar_t **)(param_1 + 0x40),*(int *)(param_1 + 0x48),piVar1,

               *(__crt_deferred_errno_cache **)(param_1 + 8));

  }

LAB_1402d6a23:

  iVar8 = *(int *)(param_1 + 0x20);

  if ((-1 < iVar8) && ((*(uint *)(param_1 + 0x28) >> 2 & 1) != 0)) {

    piVar1 = (int *)(param_1 + 0x20);

    iVar14 = 0;

    if (0 < iVar16) {

      do {

        lVar6 = *(longlong *)(param_1 + 0x460);

        if (*(longlong *)(lVar6 + 0x10) == *(longlong *)(lVar6 + 8)) {

          if (*(char *)(lVar6 + 0x18) == '\0') {

            iVar8 = -1;

          }

          else {

            iVar8 = iVar8 + 1;

          }

          *piVar1 = iVar8;

        }

        else {

          *piVar1 = iVar8 + 1;

          *(longlong *)(lVar6 + 0x10) = *(longlong *)(lVar6 + 0x10) + 1;

          *(undefined2 *)**(undefined8 **)(param_1 + 0x460) = 0x20;

          **(longlong **)(param_1 + 0x460) = **(longlong **)(param_1 + 0x460) + 2;

        }

        iVar8 = *piVar1;

      } while ((iVar8 != -1) && (iVar14 = iVar14 + 1, iVar14 < iVar16));

    }

  }

  return 1;

LAB_1402d6a01:

  *piVar1 = -1;

  goto LAB_1402d6a23;

}




