// Address: 0x1401396c0
// Ghidra name: FUN_1401396c0
// ============ 0x1401396c0 FUN_1401396c0 (size=4511) ============


void FUN_1401396c0(uint *param_1,undefined1 *param_2,int param_3)



{

  float fVar1;

  float fVar2;

  uint uVar3;

  char *pcVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  undefined8 uVar9;

  double dVar10;

  double dVar11;

  undefined8 in_stack_fffffffffffffee8;

  undefined8 uVar12;

  undefined4 uVar14;

  undefined8 uVar13;

  undefined8 in_stack_fffffffffffffef0;

  undefined4 uVar16;

  undefined8 uVar15;

  undefined8 in_stack_fffffffffffffef8;

  undefined4 uVar18;

  undefined8 uVar17;

  undefined8 in_stack_ffffffffffffff00;

  undefined4 uVar19;

  undefined8 in_stack_ffffffffffffff08;

  undefined4 uVar20;

  undefined8 in_stack_ffffffffffffff10;

  undefined4 uVar21;

  undefined8 in_stack_ffffffffffffff18;

  undefined4 uVar22;

  char local_d8 [64];

  undefined1 local_98 [128];

  undefined1 local_18 [16];

  

  uVar21 = (undefined4)((ulonglong)in_stack_ffffffffffffff10 >> 0x20);

  uVar22 = (undefined4)((ulonglong)in_stack_ffffffffffffff18 >> 0x20);

  uVar14 = (undefined4)((ulonglong)in_stack_fffffffffffffee8 >> 0x20);

  uVar16 = (undefined4)((ulonglong)in_stack_fffffffffffffef0 >> 0x20);

  uVar18 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

  uVar19 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);

  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff08 >> 0x20);

  if (param_1 == (uint *)0x0) {

    FUN_14012ef10(param_2,(longlong)param_3,"(null)");

    return;

  }

  local_d8[0] = '\0';

  local_98[0] = 0;

  if (*param_1 - 0x8000 < 0x8000) {

    FUN_14012f1a0(local_d8,"SDL_EVENT_USER",0x40);

    if (*param_1 < 0x8001) {

      local_18[0] = 0;

    }

    else {

      FUN_14012ef10(local_18,0x10,&DAT_14031a568,*param_1 - 0x8000);

    }

    uVar9 = *(undefined8 *)(param_1 + 8);

    uVar13 = *(undefined8 *)(param_1 + 6);

    uVar17 = CONCAT44(uVar18,param_1[5]);

    uVar15 = CONCAT44(uVar16,param_1[4]);

    uVar12 = *(undefined8 *)(param_1 + 2);

    FUN_14012ef10(local_98,0x80,"%s (timestamp=%I64u windowid=%u code=%d data1=%p data2=%p)",

                  local_18,uVar12,uVar15,uVar17,uVar13,uVar9);

    uVar14 = (undefined4)((ulonglong)uVar12 >> 0x20);

    uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);

    uVar18 = (undefined4)((ulonglong)uVar17 >> 0x20);

    uVar19 = (undefined4)((ulonglong)uVar13 >> 0x20);

    uVar20 = (undefined4)((ulonglong)uVar9 >> 0x20);

  }

  uVar3 = *param_1;

  if (0x400 < uVar3) {

    if (0x700 < uVar3) {

      if (uVar3 < 0x1301) {

        if (uVar3 == 0x1300) {

          pcVar6 = "SDL_EVENT_PEN_PROXIMITY_IN";

LAB_14013a4de:

          FUN_14012f1a0(local_d8,pcVar6,0x40);

          pcVar4 = " (timestamp=%I64u windowid=%u which=%u)";

          pcVar6 = (char *)CONCAT44(uVar16,param_1[5]);

          pcVar7 = (char *)CONCAT44(uVar14,param_1[4]);

          goto LAB_14013a7f6;

        }

        if (0x1001 < uVar3) {

          if (uVar3 < 0x1101) {

            if (uVar3 != 0x1100) {

              if (uVar3 == 0x1002) {

                pcVar6 = "SDL_EVENT_DROP_BEGIN";

              }

              else if (uVar3 == 0x1003) {

                pcVar6 = "SDL_EVENT_DROP_COMPLETE";

              }

              else {

                if (uVar3 != 0x1004) goto switchD_140139878_caseD_109;

                pcVar6 = "SDL_EVENT_DROP_POSITION";

              }

              goto LAB_14013a319;

            }

            pcVar6 = "SDL_EVENT_AUDIO_DEVICE_ADDED";

LAB_14013a3e8:

            FUN_14012f1a0(local_d8,pcVar6,0x40);

            pcVar6 = "false";

            if ((char)param_1[5] != '\0') {

              pcVar6 = "true";

            }

            pcVar4 = " (timestamp=%I64u which=%u recording=%s)";

            pcVar7 = (char *)CONCAT44(uVar14,param_1[4]);

            goto LAB_14013a7f6;

          }

          if (uVar3 == 0x1101) {

            pcVar6 = "SDL_EVENT_AUDIO_DEVICE_REMOVED";

            goto LAB_14013a3e8;

          }

          if (uVar3 == 0x1102) {

            pcVar6 = "SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED";

            goto LAB_14013a3e8;

          }

          if (uVar3 != 0x1200) goto switchD_140139878_caseD_109;

          FUN_14012f1a0(local_d8,"SDL_EVENT_SENSOR_UPDATE",0x40);

          pcVar8 = 

          " (timestamp=%I64u which=%d data[0]=%f data[1]=%f data[2]=%f data[3]=%f data[4]=%f data[5]=%f)"

          ;

          pcVar7 = (char *)(double)(float)param_1[10];

          pcVar6 = (char *)(double)(float)param_1[9];

          dVar11 = (double)(float)param_1[8];

          pcVar4 = (char *)(double)(float)param_1[7];

          pcVar5 = (char *)(double)(float)param_1[6];

          dVar10 = (double)(float)param_1[5];

          goto LAB_140139bce;

        }

        if (uVar3 != 0x1001) {

          if (0x711 < uVar3) {

            if (uVar3 == 0x712) {

              pcVar6 = "SDL_EVENT_PINCH_END";

              goto LAB_14013a298;

            }

            if (uVar3 == 0x900) {

              FUN_14012f1a0(local_d8,"SDL_EVENT_CLIPBOARD_UPDATE",0x40);

              goto LAB_14013a808;

            }

            if (uVar3 != 0x1000) goto switchD_140139878_caseD_109;

            pcVar6 = "SDL_EVENT_DROP_FILE";

            goto LAB_14013a319;

          }

          if (uVar3 == 0x711) {

            pcVar6 = "SDL_EVENT_PINCH_UPDATE";

LAB_14013a298:

            FUN_14012f1a0(local_d8,pcVar6,0x40);

            pcVar6 = " (timestamp=%I64u scale=%f)";

            dVar10 = (double)(float)param_1[4];

            goto LAB_140139c50;

          }

          if (uVar3 == 0x701) {

            pcVar6 = "SDL_EVENT_FINGER_UP";

          }

          else if (uVar3 == 0x702) {

            pcVar6 = "SDL_EVENT_FINGER_MOTION";

          }

          else {

            if (uVar3 != 0x703) {

              if (uVar3 != 0x710) goto switchD_140139878_caseD_109;

              pcVar6 = "SDL_EVENT_PINCH_BEGIN";

              goto LAB_14013a298;

            }

            pcVar6 = "SDL_EVENT_FINGER_CANCELED";

          }

LAB_14013a1cf:

          FUN_14012f1a0(local_d8,pcVar6,0x40);

          dVar10 = *(double *)(param_1 + 6);

          pcVar8 = 

          " (timestamp=%I64u touchid=%I64u fingerid=%I64u x=%f y=%f dx=%f dy=%f pressure=%f)";

          pcVar7 = (char *)(double)(float)param_1[0xc];

          pcVar6 = (char *)(double)(float)param_1[0xb];

          dVar11 = (double)(float)param_1[10];

          pcVar4 = (char *)(double)(float)param_1[9];

          pcVar5 = (char *)(double)(float)param_1[8];

          uVar9 = *(undefined8 *)(param_1 + 4);

          goto LAB_140139bd5;

        }

        pcVar6 = "SDL_EVENT_DROP_TEXT";

LAB_14013a319:

        FUN_14012f1a0(local_d8,pcVar6,0x40);

        pcVar7 = " (data=\'%s\' timestamp=%I64u windowid=%u x=%f y=%f)";

        uVar9 = *(undefined8 *)(param_1 + 10);

        dVar10 = (double)(float)param_1[6];

        dVar11 = (double)(float)param_1[5];

        pcVar6 = (char *)CONCAT44(uVar16,param_1[4]);

        uVar13 = *(undefined8 *)(param_1 + 2);

        goto LAB_14013999b;

      }

      if (0x1400 < uVar3) {

        if (uVar3 < 0x2001) {

          if (uVar3 != 0x2000) {

            if (uVar3 == 0x1401) {

              pcVar6 = "SDL_EVENT_CAMERA_DEVICE_REMOVED";

            }

            else if (uVar3 == 0x1402) {

              pcVar6 = "SDL_EVENT_CAMERA_DEVICE_APPROVED";

            }

            else {

              if (uVar3 != 0x1403) goto switchD_140139878_caseD_109;

              pcVar6 = "SDL_EVENT_CAMERA_DEVICE_DENIED";

            }

            goto LAB_140139c32;

          }

          pcVar6 = "SDL_EVENT_RENDER_TARGETS_RESET";

        }

        else if (uVar3 == 0x2001) {

          pcVar6 = "SDL_EVENT_RENDER_DEVICE_RESET";

        }

        else {

          if (uVar3 != 0x2002) {

            if (uVar3 == 0x7f00) goto LAB_14013a808;

            goto switchD_140139878_caseD_109;

          }

          pcVar6 = "SDL_EVENT_RENDER_DEVICE_LOST";

        }

        FUN_14012f1a0(local_d8,pcVar6,0x40);

        pcVar4 = " (timestamp=%I64u event=%s windowid=%u)";

        pcVar6 = (char *)CONCAT44(uVar16,param_1[4]);

        pcVar7 = local_d8;

LAB_14013a7f6:

        FUN_14012ef10(local_98,0x80,pcVar4,*(undefined8 *)(param_1 + 2),pcVar7,pcVar6);

        goto LAB_14013a808;

      }

      if (uVar3 == 0x1400) {

        pcVar6 = "SDL_EVENT_CAMERA_DEVICE_ADDED";

        goto LAB_140139c32;

      }

      switch(uVar3) {

      case 0x1301:

        pcVar6 = "SDL_EVENT_PEN_PROXIMITY_OUT";

        goto LAB_14013a4de;

      case 0x1302:

        pcVar6 = "SDL_EVENT_PEN_DOWN";

        break;

      case 0x1303:

        pcVar6 = "SDL_EVENT_PEN_UP";

        break;

      case 0x1304:

        pcVar6 = "SDL_EVENT_PEN_BUTTON_DOWN";

        goto LAB_14013a693;

      case 0x1305:

        pcVar6 = "SDL_EVENT_PEN_BUTTON_UP";

LAB_14013a693:

        FUN_14012f1a0(local_d8,pcVar6,0x40);

        pcVar7 = "up";

        pcVar8 = " (timestamp=%I64u windowid=%u which=%u pen_state=%u x=%g y=%g button=%u state=%s)"

        ;

        dVar11 = (double)(float)param_1[8];

        if (*(char *)((longlong)param_1 + 0x25) != '\0') {

          pcVar7 = "down";

        }

        pcVar6 = (char *)CONCAT44(uVar21,(uint)(byte)param_1[9]);

        pcVar4 = (char *)(double)(float)param_1[7];

        pcVar5 = (char *)CONCAT44(uVar18,param_1[6]);

        goto LAB_140139bc7;

      case 0x1306:

        FUN_14012f1a0(local_d8,"SDL_EVENT_PEN_MOTION",0x40);

        fVar1 = (float)param_1[8];

        pcVar6 = " (timestamp=%I64u windowid=%u which=%u pen_state=%u x=%g y=%g)";

        fVar2 = (float)param_1[7];

        dVar10 = (double)CONCAT44(uVar18,param_1[6]);

        goto LAB_14013a1a3;

      case 0x1307:

        FUN_14012f1a0(local_d8,"SDL_EVENT_PEN_AXIS",0x40);

        uVar3 = param_1[9];

        if (((int)uVar3 < 0) || (6 < uVar3)) {

          pcVar6 = "[UNKNOWN]";

        }

        else {

          pcVar6 = (&PTR_s_PRESSURE_1403e1160)[(int)uVar3];

        }

        pcVar8 = " (timestamp=%I64u windowid=%u which=%u pen_state=%u x=%g y=%g axis=%s value=%g)";

        pcVar7 = (char *)(double)(float)param_1[10];

        dVar11 = (double)(float)param_1[8];

        pcVar4 = (char *)(double)(float)param_1[7];

        pcVar5 = (char *)CONCAT44(uVar18,param_1[6]);

        goto LAB_140139bc7;

      default:

        goto switchD_140139878_caseD_109;

      }

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      pcVar7 = "up";

      if (*(char *)((longlong)param_1 + 0x25) != '\0') {

        pcVar7 = "down";

      }

      pcVar8 = " (timestamp=%I64u windowid=%u which=%u pen_state=%u x=%g y=%g eraser=%s state=%s)";

      pcVar6 = "no";

      if ((char)param_1[9] != '\0') {

        pcVar6 = "yes";

      }

      dVar11 = (double)(float)param_1[8];

      pcVar4 = (char *)(double)(float)param_1[7];

      pcVar5 = (char *)CONCAT44(uVar18,param_1[6]);

LAB_140139bc7:

      dVar10 = (double)CONCAT44(uVar16,param_1[5]);

LAB_140139bce:

      uVar9 = CONCAT44(uVar14,param_1[4]);

LAB_140139bd5:

      FUN_14012ef10(local_98,0x80,pcVar8,*(undefined8 *)(param_1 + 2),uVar9,dVar10,pcVar5,pcVar4,

                    dVar11,pcVar6,pcVar7);

      goto LAB_14013a808;

    }

    if (uVar3 == 0x700) {

      pcVar6 = "SDL_EVENT_FINGER_DOWN";

      goto LAB_14013a1cf;

    }

    if (uVar3 < 0x601) {

      if (uVar3 != 0x600) {

        if (uVar3 == 0x401) {

          pcVar6 = "SDL_EVENT_MOUSE_BUTTON_DOWN";

        }

        else {

          if (uVar3 != 0x402) {

            if (uVar3 == 0x403) {

              FUN_14012f1a0(local_d8,"SDL_EVENT_MOUSE_WHEEL",0x40);

              pcVar7 = "flipped";

              pcVar8 = 

              " (timestamp=%I64u windowid=%u which=%u x=%g y=%g integer_x=%d integer_y=%d direction=%s)"

              ;

              if (param_1[8] == 0) {

                pcVar7 = "normal";

              }

              pcVar6 = (char *)CONCAT44(uVar21,param_1[0xc]);

              dVar11 = (double)CONCAT44(uVar20,param_1[0xb]);

              pcVar4 = (char *)(double)(float)param_1[7];

              pcVar5 = (char *)(double)(float)param_1[6];

              goto LAB_140139bc7;

            }

            if (uVar3 == 0x404) {

              pcVar6 = "SDL_EVENT_MOUSE_ADDED";

            }

            else {

              if (uVar3 != 0x405) goto switchD_140139878_caseD_109;

              pcVar6 = "SDL_EVENT_MOUSE_REMOVED";

            }

            goto LAB_140139c32;

          }

          pcVar6 = "SDL_EVENT_MOUSE_BUTTON_UP";

        }

        FUN_14012f1a0(local_d8,pcVar6,0x40);

        pcVar4 = "released";

        if (*(char *)((longlong)param_1 + 0x19) != '\0') {

          pcVar4 = "pressed";

        }

        pcVar7 = (char *)(double)(float)param_1[8];

        pcVar8 = " (timestamp=%I64u windowid=%u which=%u button=%u state=%s clicks=%u x=%g y=%g)";

        pcVar6 = (char *)(double)(float)param_1[7];

        dVar11 = (double)CONCAT44(uVar20,(uint)*(byte *)((longlong)param_1 + 0x1a));

        pcVar5 = (char *)CONCAT44(uVar18,(uint)(byte)param_1[6]);

        goto LAB_140139bc7;

      }

      pcVar6 = "SDL_EVENT_JOYSTICK_AXIS_MOTION";

LAB_140139f12:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      pcVar7 = " (timestamp=%I64u which=%d axis=%u value=%d)";

      pcVar6 = (char *)CONCAT44(uVar18,(int)(short)param_1[6]);

      uVar9 = CONCAT44(uVar16,(uint)(byte)param_1[5]);

      goto LAB_140139cdd;

    }

    switch(uVar3) {

    case 0x601:

      FUN_14012f1a0(local_d8,"SDL_EVENT_JOYSTICK_BALL_MOTION",0x40);

      pcVar7 = " (timestamp=%I64u which=%d ball=%u xrel=%d yrel=%d)";

      dVar10 = (double)CONCAT44(uVar19,(int)*(short *)((longlong)param_1 + 0x1a));

      dVar11 = (double)CONCAT44(uVar18,(int)(short)param_1[6]);

      pcVar6 = (char *)CONCAT44(uVar16,(uint)(byte)param_1[5]);

      goto LAB_140139990;

    case 0x602:

      FUN_14012f1a0(local_d8,"SDL_EVENT_JOYSTICK_HAT_MOTION",0x40);

      pcVar7 = " (timestamp=%I64u which=%d hat=%u value=%u)";

      pcVar6 = (char *)CONCAT44(uVar18,(uint)*(byte *)((longlong)param_1 + 0x15));

      uVar9 = CONCAT44(uVar16,(uint)(byte)param_1[5]);

      goto LAB_140139cdd;

    case 0x603:

      pcVar6 = "SDL_EVENT_JOYSTICK_BUTTON_DOWN";

      goto LAB_140139fde;

    case 0x604:

      pcVar6 = "SDL_EVENT_JOYSTICK_BUTTON_UP";

      goto LAB_140139fde;

    case 0x605:

      pcVar6 = "SDL_EVENT_JOYSTICK_ADDED";

      break;

    case 0x606:

      pcVar6 = "SDL_EVENT_JOYSTICK_REMOVED";

      break;

    case 0x607:

      FUN_14012f1a0(local_d8,"SDL_EVENT_JOYSTICK_BATTERY_UPDATED",0x40);

      pcVar7 = " (timestamp=%I64u which=%d state=%u percent=%d)";

      pcVar6 = (char *)CONCAT44(uVar18,param_1[6]);

      uVar3 = param_1[5];

      goto LAB_140139cd9;

    case 0x608:

      pcVar6 = "SDL_EVENT_JOYSTICK_UPDATE_COMPLETE";

      break;

    default:

      goto switchD_140139878_caseD_109;

    case 0x650:

      pcVar6 = "SDL_EVENT_GAMEPAD_AXIS_MOTION";

      goto LAB_140139f12;

    case 0x651:

      pcVar6 = "SDL_EVENT_GAMEPAD_BUTTON_DOWN";

      goto LAB_140139fde;

    case 0x652:

      pcVar6 = "SDL_EVENT_GAMEPAD_BUTTON_UP";

LAB_140139fde:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      uVar3 = (uint)(byte)param_1[5];

      pcVar6 = "released";

      if (*(char *)((longlong)param_1 + 0x15) != '\0') {

        pcVar6 = "pressed";

      }

      pcVar7 = " (timestamp=%I64u which=%d button=%u state=%s)";

LAB_140139cd9:

      uVar9 = CONCAT44(uVar16,uVar3);

LAB_140139cdd:

      FUN_14012ef10(local_98,0x80,pcVar7,*(undefined8 *)(param_1 + 2),CONCAT44(uVar14,param_1[4]),

                    uVar9,pcVar6);

      goto LAB_14013a808;

    case 0x653:

      pcVar6 = "SDL_EVENT_GAMEPAD_ADDED";

      break;

    case 0x654:

      pcVar6 = "SDL_EVENT_GAMEPAD_REMOVED";

      break;

    case 0x655:

      pcVar6 = "SDL_EVENT_GAMEPAD_REMAPPED";

      break;

    case 0x656:

      pcVar6 = "SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN";

      goto LAB_14013a0dc;

    case 0x657:

      pcVar6 = "SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION";

      goto LAB_14013a0dc;

    case 0x658:

      pcVar6 = "SDL_EVENT_GAMEPAD_TOUCHPAD_UP";

LAB_14013a0dc:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      FUN_14012ef10(local_98,0x80,

                    " (timestamp=%I64u which=%d touchpad=%d finger=%d x=%f y=%f pressure=%f)",

                    *(undefined8 *)(param_1 + 2),CONCAT44(uVar14,param_1[4]),

                    CONCAT44(uVar16,param_1[5]),CONCAT44(uVar18,param_1[6]),

                    (double)(float)param_1[7],(double)(float)param_1[8],(double)(float)param_1[9]);

      goto LAB_14013a808;

    case 0x659:

      FUN_14012f1a0(local_d8,"SDL_EVENT_GAMEPAD_SENSOR_UPDATE",0x40);

      fVar1 = (float)param_1[8];

      pcVar6 = " (timestamp=%I64u which=%d sensor=%d data[0]=%f data[1]=%f data[2]=%f)";

      fVar2 = (float)param_1[7];

      dVar10 = (double)(float)param_1[6];

LAB_14013a1a3:

      FUN_14012ef10(local_98,0x80,pcVar6,*(undefined8 *)(param_1 + 2),CONCAT44(uVar14,param_1[4]),

                    CONCAT44(uVar16,param_1[5]),dVar10,(double)fVar2,(double)fVar1);

      goto LAB_14013a808;

    case 0x65a:

      pcVar6 = "SDL_EVENT_GAMEPAD_UPDATE_COMPLETE";

      break;

    case 0x65b:

      pcVar6 = "SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED";

    }

    FUN_14012f1a0(local_d8,pcVar6,0x40);

    pcVar6 = " (timestamp=%I64u which=%d)";

LAB_140139c49:

    dVar10 = (double)CONCAT44(uVar14,param_1[4]);

LAB_140139c50:

    FUN_14012ef10(local_98,0x80,pcVar6,*(undefined8 *)(param_1 + 2),dVar10);

    goto LAB_14013a808;

  }

  if (uVar3 == 0x400) {

    FUN_14012f1a0(local_d8,"SDL_EVENT_MOUSE_MOTION",0x40);

    pcVar8 = " (timestamp=%I64u windowid=%u which=%u state=%u x=%g y=%g xrel=%g yrel=%g)";

    pcVar7 = (char *)(double)(float)param_1[10];

    pcVar6 = (char *)(double)(float)param_1[9];

    dVar11 = (double)(float)param_1[8];

    pcVar4 = (char *)(double)(float)param_1[7];

    pcVar5 = (char *)CONCAT44(uVar18,param_1[6]);

    goto LAB_140139bc7;

  }

  if (0x202 < uVar3) {

    if (uVar3 < 0x301) {

      if (uVar3 == 0x300) {

        pcVar6 = "SDL_EVENT_KEY_DOWN";

        goto LAB_140139b64;

      }

      switch(uVar3) {

      case 0x203:

        pcVar6 = "SDL_EVENT_WINDOW_HIDDEN";

        break;

      case 0x204:

        pcVar6 = "SDL_EVENT_WINDOW_EXPOSED";

        break;

      case 0x205:

        pcVar6 = "SDL_EVENT_WINDOW_MOVED";

        break;

      case 0x206:

        pcVar6 = "SDL_EVENT_WINDOW_RESIZED";

        break;

      case 0x207:

        pcVar6 = "SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED";

        break;

      case 0x208:

        pcVar6 = "SDL_EVENT_WINDOW_METAL_VIEW_RESIZED";

        break;

      case 0x209:

        pcVar6 = "SDL_EVENT_WINDOW_MINIMIZED";

        break;

      case 0x20a:

        pcVar6 = "SDL_EVENT_WINDOW_MAXIMIZED";

        break;

      case 0x20b:

        pcVar6 = "SDL_EVENT_WINDOW_RESTORED";

        break;

      case 0x20c:

        pcVar6 = "SDL_EVENT_WINDOW_MOUSE_ENTER";

        break;

      case 0x20d:

        pcVar6 = "SDL_EVENT_WINDOW_MOUSE_LEAVE";

        break;

      case 0x20e:

        pcVar6 = "SDL_EVENT_WINDOW_FOCUS_GAINED";

        break;

      case 0x20f:

        pcVar6 = "SDL_EVENT_WINDOW_FOCUS_LOST";

        break;

      case 0x210:

        pcVar6 = "SDL_EVENT_WINDOW_CLOSE_REQUESTED";

        break;

      case 0x211:

        pcVar6 = "SDL_EVENT_WINDOW_HIT_TEST";

        break;

      case 0x212:

        pcVar6 = "SDL_EVENT_WINDOW_ICCPROF_CHANGED";

        break;

      case 0x213:

        pcVar6 = "SDL_EVENT_WINDOW_DISPLAY_CHANGED";

        break;

      case 0x214:

        pcVar6 = "SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED";

        break;

      case 0x215:

        pcVar6 = "SDL_EVENT_WINDOW_SAFE_AREA_CHANGED";

        break;

      case 0x216:

        pcVar6 = "SDL_EVENT_WINDOW_OCCLUDED";

        break;

      case 0x217:

        pcVar6 = "SDL_EVENT_WINDOW_ENTER_FULLSCREEN";

        break;

      case 0x218:

        pcVar6 = "SDL_EVENT_WINDOW_LEAVE_FULLSCREEN";

        break;

      case 0x219:

        pcVar6 = "SDL_EVENT_WINDOW_DESTROYED";

        break;

      case 0x21a:

        pcVar6 = "SDL_EVENT_WINDOW_HDR_STATE_CHANGED";

        break;

      default:

        goto switchD_140139878_caseD_109;

      }

LAB_1401399fa:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      pcVar7 = " (timestamp=%I64u windowid=%u event=%s data1=%d data2=%d)";

      goto LAB_140139978;

    }

    switch(uVar3) {

    case 0x301:

      pcVar6 = "SDL_EVENT_KEY_UP";

LAB_140139b64:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      pcVar7 = (char *)CONCAT44(uVar22,(uint)(ushort)param_1[8]);

      pcVar4 = "false";

      if (*(char *)((longlong)param_1 + 0x25) != '\0') {

        pcVar4 = "true";

      }

      pcVar5 = "released";

      pcVar6 = (char *)CONCAT44(uVar21,param_1[7]);

      if ((char)param_1[9] != '\0') {

        pcVar5 = "pressed";

      }

      dVar11 = (double)CONCAT44(uVar20,param_1[6]);

      pcVar8 = 

      " (timestamp=%I64u windowid=%u which=%u state=%s repeat=%s scancode=%u keycode=%u mod=0x%x)";

      goto LAB_140139bc7;

    case 0x302:

      FUN_14012f1a0(local_d8,"SDL_EVENT_TEXT_EDITING",0x40);

      pcVar7 = " (timestamp=%I64u windowid=%u text=\'%s\' start=%d length=%d)";

      dVar10 = (double)CONCAT44(uVar19,param_1[9]);

      dVar11 = (double)CONCAT44(uVar18,param_1[8]);

      pcVar6 = *(char **)(param_1 + 6);

      goto LAB_140139990;

    case 0x303:

      FUN_14012f1a0(local_d8,"SDL_EVENT_TEXT_INPUT",0x40);

      pcVar6 = *(char **)(param_1 + 6);

      pcVar4 = " (timestamp=%I64u windowid=%u text=\'%s\')";

      pcVar7 = (char *)CONCAT44(uVar14,param_1[4]);

      goto LAB_14013a7f6;

    case 0x304:

      FUN_14012f1a0(local_d8,"SDL_EVENT_KEYMAP_CHANGED",0x40);

      break;

    case 0x305:

      pcVar6 = "SDL_EVENT_KEYBOARD_ADDED";

      goto LAB_140139c32;

    case 0x306:

      pcVar6 = "SDL_EVENT_KEYBOARD_REMOVED";

LAB_140139c32:

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      pcVar6 = " (timestamp=%I64u which=%u)";

      goto LAB_140139c49;

    case 0x307:

      FUN_14012f1a0(local_d8,"SDL_EVENT_TEXT_EDITING_CANDIDATES",0x40);

      pcVar7 = " (timestamp=%I64u windowid=%u num_candidates=%d selected_candidate=%d)";

      pcVar6 = (char *)CONCAT44(uVar18,param_1[9]);

      uVar3 = param_1[8];

      goto LAB_140139cd9;

    case 0x308:

      FUN_14012f1a0(local_d8,"SDL_EVENT_SCREEN_KEYBOARD_SHOWN",0x40);

      break;

    case 0x309:

      FUN_14012f1a0(local_d8,"SDL_EVENT_SCREEN_KEYBOARD_HIDDEN",0x40);

      break;

    default:

      goto switchD_140139878_caseD_109;

    }

    goto LAB_14013a808;

  }

  if (uVar3 == 0x202) {

    pcVar6 = "SDL_EVENT_WINDOW_SHOWN";

    goto LAB_1401399fa;

  }

  if (uVar3 < 0x101) {

    if (uVar3 == 0x100) {

      FUN_14012f1a0(local_d8,"SDL_EVENT_QUIT",0x40);

      FUN_14012ef10(local_98,0x80," (timestamp=%I64u)",*(undefined8 *)(param_1 + 2));

      goto LAB_14013a808;

    }

    if (uVar3 == 0) {

      FUN_14012f1a0(local_d8,"SDL_EVENT_FIRST",0x40);

      FUN_14012f1a0(local_98," (THIS IS PROBABLY A BUG!)",0x80);

      goto LAB_14013a808;

    }

switchD_140139878_caseD_109:

    if (local_d8[0] == '\0') {

      pcVar6 = "USER";

      if (uVar3 < 0x8000) {

        pcVar6 = "UNKNOWN";

      }

      FUN_14012f1a0(local_d8,pcVar6,0x40);

      FUN_14012ef10(local_98,0x80," 0x%x",*param_1);

    }

    goto LAB_14013a808;

  }

  switch(uVar3) {

  case 0x101:

    FUN_14012f1a0(local_d8,"SDL_EVENT_TERMINATING",0x40);

    goto LAB_14013a808;

  case 0x102:

    FUN_14012f1a0(local_d8,"SDL_EVENT_LOW_MEMORY",0x40);

    goto LAB_14013a808;

  case 0x103:

    FUN_14012f1a0(local_d8,"SDL_EVENT_WILL_ENTER_BACKGROUND",0x40);

    goto LAB_14013a808;

  case 0x104:

    FUN_14012f1a0(local_d8,"SDL_EVENT_DID_ENTER_BACKGROUND",0x40);

    goto LAB_14013a808;

  case 0x105:

    FUN_14012f1a0(local_d8,"SDL_EVENT_WILL_ENTER_FOREGROUND",0x40);

    goto LAB_14013a808;

  case 0x106:

    FUN_14012f1a0(local_d8,"SDL_EVENT_DID_ENTER_FOREGROUND",0x40);

    goto LAB_14013a808;

  case 0x107:

    FUN_14012f1a0(local_d8,"SDL_EVENT_LOCALE_CHANGED",0x40);

    goto LAB_14013a808;

  case 0x108:

    FUN_14012f1a0(local_d8,"SDL_EVENT_SYSTEM_THEME_CHANGED",0x40);

    goto LAB_14013a808;

  default:

    goto switchD_140139878_caseD_109;

  case 0x151:

    pcVar6 = "SDL_EVENT_DISPLAY_ORIENTATION";

    break;

  case 0x152:

    pcVar6 = "SDL_EVENT_DISPLAY_ADDED";

    break;

  case 0x153:

    pcVar6 = "SDL_EVENT_DISPLAY_REMOVED";

    break;

  case 0x154:

    pcVar6 = "SDL_EVENT_DISPLAY_MOVED";

    break;

  case 0x155:

    pcVar6 = "SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED";

    break;

  case 0x156:

    pcVar6 = "SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED";

    break;

  case 0x157:

    pcVar6 = "SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED";

    break;

  case 0x158:

    pcVar6 = "SDL_EVENT_DISPLAY_USABLE_BOUNDS_CHANGED";

  }

  FUN_14012f1a0(local_d8,pcVar6,0x40);

  pcVar7 = " (timestamp=%I64u display=%u event=%s data1=%d, data2=%d)";

LAB_140139978:

  dVar10 = (double)CONCAT44(uVar19,param_1[6]);

  dVar11 = (double)CONCAT44(uVar18,param_1[5]);

  pcVar6 = local_d8;

LAB_140139990:

  uVar9 = *(undefined8 *)(param_1 + 2);

  uVar13 = CONCAT44(uVar14,param_1[4]);

LAB_14013999b:

  FUN_14012ef10(local_98,0x80,pcVar7,uVar9,uVar13,pcVar6,dVar11,dVar10);

LAB_14013a808:

  if (local_d8[0] == '\0') {

    if ((param_2 != (undefined1 *)0x0) && (0 < param_3)) {

      *param_2 = 0;

    }

  }

  else {

    FUN_14012ef10(param_2,(longlong)param_3,&DAT_14031bb40,local_d8,local_98);

  }

  return;

}




