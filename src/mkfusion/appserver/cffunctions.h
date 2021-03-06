#pragma once

#include "qmkfusionexception.h"
#include "qcfworkerthread.h"
#include "qcfvariant.h"
//#include "common.h"

#include <QStringList>
#include <QDateTime>
#include <QString>


Q_DECL_EXPORT double cf_Abs(double number);
Q_DECL_EXPORT double cf_ACos(double number);
Q_DECL_EXPORT void cf_AddSOAPRequestHeader(QCFVariant &webservice, const QString &_namespace, const QString &name, const QCFVariant &value, bool mustunderstand);
Q_DECL_EXPORT void cf_AddSOAPResponseHeader(const QString &_namespace, const QString &name, const QCFVariant &value, bool mustunderstand);
Q_DECL_EXPORT QString cf_AjaxLink(const QString &URL);
Q_DECL_EXPORT void cf_AjaxOnLoad(const QString &functionName);
Q_DECL_EXPORT bool cf_ArrayAppend(QCFVariant &array, const QCFVariant &value);
Q_DECL_EXPORT double cf_ArrayAvg(const QCFVariant &array);
Q_DECL_EXPORT bool cf_ArrayClear(QCFVariant &array);
Q_DECL_EXPORT bool cf_ArrayDeleteAt(QCFVariant &array, int position);
Q_DECL_EXPORT bool cf_ArrayInsertAt(QCFVariant &array, int position, const QCFVariant &value);
Q_DECL_EXPORT bool cf_ArrayIsDefined(const QCFVariant &array, int elementIndex);
Q_DECL_EXPORT bool cf_ArrayIsEmpty(const QCFVariant &array);
Q_DECL_EXPORT int cf_ArrayLen(const QCFVariant &array);
Q_DECL_EXPORT double cf_ArrayMax(const QCFVariant &array);
Q_DECL_EXPORT double cf_ArrayMin(const QCFVariant &array);
Q_DECL_EXPORT QCFVariant cf_ArrayNew(int dimension);
Q_DECL_EXPORT bool cf_ArrayPrepend(QCFVariant &array, const QCFVariant &value);
Q_DECL_EXPORT bool cf_ArrayResize(QCFVariant &array, int minSize);
Q_DECL_EXPORT bool cf_ArraySet(QCFVariant &array, int start, int end, const QCFVariant &value);
Q_DECL_EXPORT bool cf_ArraySort(QCFVariant &array, const QString &sort_type, const QString &sort_order);
Q_DECL_EXPORT double cf_ArraySum(const QCFVariant &array);
Q_DECL_EXPORT bool cf_ArraySwap(QCFVariant &array, int position1, int position2);
Q_DECL_EXPORT QString cf_ArrayToList(const QCFVariant &array, const QString &delimiter = ",");
Q_DECL_EXPORT int cf_Asc(const QString &string);
Q_DECL_EXPORT double cf_ASin(double number);
Q_DECL_EXPORT double cf_Atn(double number);
Q_DECL_EXPORT QString cf_BinaryDecode(const QString &string, const QString &binaryencoding);
Q_DECL_EXPORT QString cf_BinaryEncode(const QString &binarydata, const QString &encoding);
Q_DECL_EXPORT int cf_BitAnd(int number1, int number2);
Q_DECL_EXPORT int cf_BitMaskClear(int number, int start, int length);
Q_DECL_EXPORT int cf_BitMaskRead(int number, int start, int length);
Q_DECL_EXPORT int cf_BitMaskSet(int number, int mask, int start, int length);
Q_DECL_EXPORT int cf_BitNot(int number);
Q_DECL_EXPORT int cf_BitOr(int number1, int number2);
Q_DECL_EXPORT int cf_BitSHLN(int number, int count);
Q_DECL_EXPORT int cf_BitSHRN(int number, int count);
Q_DECL_EXPORT int cf_BitXor(int number1, int number2);
Q_DECL_EXPORT double cf_Ceiling(double number);
Q_DECL_EXPORT QString cf_CharsetDecode(const QString &string, const QString &encoding);
Q_DECL_EXPORT QString cf_CharsetEncode(const QString &binaryobject, const QString &encoding);
Q_DECL_EXPORT QString cf_Chr(int number);
Q_DECL_EXPORT QString cf_CJustify(const QString &string, int length);
Q_DECL_EXPORT int cf_Compare(const QString &string1, const QString &string2);
Q_DECL_EXPORT int cf_CompareNoCase(const QString &string1, const QString &string2);
Q_DECL_EXPORT double cf_Cos(double number);
Q_DECL_EXPORT QCFVariant cf_CreateDate(int year, int month, int day);
Q_DECL_EXPORT QCFVariant cf_CreateDateTime(int year, int month, int day, int hour, int minute, int second);
Q_DECL_EXPORT QCFVariant cf_CreateObject(QCFWorkerThread *thisTemplate, const QString &type, const QString &component_name);
Q_DECL_EXPORT QCFVariant cf_CreateODBCDate(const QDateTime &date);
Q_DECL_EXPORT QCFVariant cf_CreateODBCDateTime(const QDateTime &date);
Q_DECL_EXPORT QCFVariant cf_CreateODBCTime(const QDateTime &date);
Q_DECL_EXPORT QCFVariant cf_CreateTime(int hour, int minute, int second);
Q_DECL_EXPORT QCFVariant cf_CreateTimeSpan(int days, int hours, int minutes, int seconds);
Q_DECL_EXPORT QString cf_CreateUUID();
Q_DECL_EXPORT QDateTime cf_DateAdd(const QString &datepart, int number, QDateTime &date);
Q_DECL_EXPORT int cf_DateCompare(const QDateTime &date1, const QDateTime &date2, const QString &datePart = "s");
Q_DECL_EXPORT QString cf_DateConvert(const QString &conversion_type, const QDateTime &date);
Q_DECL_EXPORT int cf_DateDiff(const QString &datepart, const QDateTime &date1, const QDateTime &date2);
Q_DECL_EXPORT QString cf_DateFormat(const QDateTime &date, const QString &mask);
Q_DECL_EXPORT int cf_DatePart(const QString &datepart, const QDateTime &date);
Q_DECL_EXPORT int cf_Day(const QDateTime &date);
Q_DECL_EXPORT int cf_DayOfWeek(const QDateTime &date);
Q_DECL_EXPORT QString cf_DayOfWeekAsString(int day_of_week, const QString &locale = "");
Q_DECL_EXPORT int cf_DayOfYear(const QDateTime &date);
Q_DECL_EXPORT int cf_DaysInMonth(const QDateTime &date);
Q_DECL_EXPORT int cf_DaysInYear(const QDateTime &date);
Q_DECL_EXPORT QString cf_DE(const QString &string);
Q_DECL_EXPORT QString cf_DecimalFormat(double number);
Q_DECL_EXPORT double cf_DecrementValue(double number);
Q_DECL_EXPORT QString cf_Decrypt(const QString &encrypted_string, const QString &key, const QString &algorithm = "CFMX_COMPAT", const QString &encoding = "UU", const QString &IVorSalt = "", int iterations = 1);
Q_DECL_EXPORT QString cf_DecryptBinary(const QString &bytes, const QString &key, const QString &algorithm = "CFMX_COMPAT", const QString &IVorSalt = "UU", int iterations = 1);
Q_DECL_EXPORT bool cf_DeleteClientVariable(const QString &name);
Q_DECL_EXPORT QString cf_DeserializeJSON(const QString &JSONVar, bool strictMapping = true);
Q_DECL_EXPORT bool cf_DirectoryExists(const QString &absolute_path);
Q_DECL_EXPORT QString cf_DollarFormat(double number);
Q_DECL_EXPORT QCFVariant cf_DotNetToCFType(const QCFVariant &variable_name);
Q_DECL_EXPORT QCFVariant cf_Duplicate(const QCFVariant &variable_name);
Q_DECL_EXPORT QString cf_Encrypt(const QString &string, const QString &key, const QString &algorithm = "CFMX_COMPAT", const QString &encoding = "UU", const QString &IVorSalt = "", int iterations = 1);
Q_DECL_EXPORT QString cf_EncryptBinary(const QString &bytes, const QString &key, const QString &algorithm = "CFMX_COMPAT", const QString &IVorSalt = "UU", int iterations = 1);
Q_DECL_EXPORT QCFVariant cf_Evaluate(const QStringList &string_expressions);
Q_DECL_EXPORT double cf_Exp(double number);
Q_DECL_EXPORT QString cf_ExpandPath(const QString &relative_path);
Q_DECL_EXPORT void cf_FileClose(QCFVariant &fileObj);
Q_DECL_EXPORT void cf_FileCopy(const QString &source, const QString &destination);
Q_DECL_EXPORT void cf_FileDelete(const QString &filepath);
Q_DECL_EXPORT bool cf_FileExists(const QString &absolute_path);
Q_DECL_EXPORT bool cf_FileIsEOF(QCFVariant &fileObj);
Q_DECL_EXPORT void cf_FileMove(const QString &source, const QString &destination);
Q_DECL_EXPORT QCFVariant cf_FileOpen(const QString &filepath, const QString mode = "read", const QString charset = "");
Q_DECL_EXPORT QString cf_FileRead(const QString &filepath, const QString charset = "");
Q_DECL_EXPORT QString cf_FileRead(QCFVariant &fileObj, int buffersize = -1);
Q_DECL_EXPORT QCFVariant cf_FileReadBinary(const QString &filepath);
Q_DECL_EXPORT QString cf_FileReadLine(QCFVariant &fileObj);
Q_DECL_EXPORT void cf_FileSetAccessMode(const QString &filepath, const QString mode); // TODO: Make this available only under Linux
Q_DECL_EXPORT void cf_FileSetAttribute(const QString &filepath, const QString mode); // TODO: Make this available only under Windows
Q_DECL_EXPORT void cf_FileSetLastModified(const QString &filepath, const QDateTime &date);
Q_DECL_EXPORT void cf_FileWrite(const QString &filepath, const QString &data, const QString &charset = "");
Q_DECL_EXPORT void cf_FileWrite(QCFVariant &fileObj, const QString &data);
Q_DECL_EXPORT int cf_Find(const QString &substring, const QString &string, int start = 1);
Q_DECL_EXPORT int cf_FindNoCase(const QString &substring, const QString &string, int start = 1);
Q_DECL_EXPORT int cf_FindOneOf(const QString &set, const QString &string, int start = 1);
Q_DECL_EXPORT int cf_FirstDayOfMonth(const QDateTime &date);
Q_DECL_EXPORT int cf_Fix(double value);
Q_DECL_EXPORT QString cf_FormatBaseN(int number, int radix);
Q_DECL_EXPORT QString cf_GenerateSecretKey(const QString &algorithm, int keysize = -1);
Q_DECL_EXPORT QString cf_GetAuthUser();
Q_DECL_EXPORT QCFVariant cf_GetBaseTagData(QCFWorkerThread *thisTemplate, const QString &tagname, int instancenumber = 1);
Q_DECL_EXPORT QString cf_GetBaseTagList(QCFWorkerThread *thisTemplate);
Q_DECL_EXPORT QString cf_GetBaseTemplatePath();
Q_DECL_EXPORT QString cf_GetClientVariablesList();
Q_DECL_EXPORT QCFVariant cf_GetComponentMetaData(const QString &path);
Q_DECL_EXPORT QString cf_GetContextRoot();
Q_DECL_EXPORT QString cf_GetCurrentTemplatePath();
Q_DECL_EXPORT QString cf_GetDirectoryFromPath(const QString &path);
Q_DECL_EXPORT QString cf_GetEncoding(const QString &scope_name);
Q_DECL_EXPORT QCFVariant cf_GetException(const QCFVariant &object);
Q_DECL_EXPORT QString cf_GetFileFromPath(const QString &path);
Q_DECL_EXPORT QCFVariant cf_GetFileInfo(const QString &path);
Q_DECL_EXPORT QString cf_GetFunctionList();
Q_DECL_EXPORT QCFVariant cf_GetGatewayHelper(const QString &gatewayID);
Q_DECL_EXPORT QCFVariant cf_GetHttpRequestData();
Q_DECL_EXPORT QString cf_GetHttpTimeString(const QDateTime &date_time_object);
Q_DECL_EXPORT int cf_GetK2ServerDocCount();
Q_DECL_EXPORT int cf_GetK2ServerDocCountLimit();
Q_DECL_EXPORT QString cf_GetLocale();
Q_DECL_EXPORT QString cf_GetLocaleDisplayName(const QString &locale = "", const QString &inlocale = "");
Q_DECL_EXPORT QString cf_GetLocalHostIP();
Q_DECL_EXPORT QCFVariant cf_GetMetaData(const QCFVariant &object);
Q_DECL_EXPORT QCFVariant cf_GetMetricData(const QString &mode);
Q_DECL_EXPORT QCFVariant cf_GetPageContext();
Q_DECL_EXPORT QCFVariant cf_GetPrinterInfo(const QString &printer);
Q_DECL_EXPORT QCFVariant cf_GetProfileSections(const QString &iniFile);
Q_DECL_EXPORT QCFVariant cf_GetProfileString(const QString &iniFile, const QString &section, const QString &entry);
Q_DECL_EXPORT QString cf_GetReadableImageFormats();
Q_DECL_EXPORT QCFVariant cf_GetSOAPRequest();
Q_DECL_EXPORT QCFVariant cf_GetSOAPRequestHeader(const QString &_namespace, const QString &name, bool asXML = false);
Q_DECL_EXPORT QCFVariant cf_GetSOAPResponse(QCFVariant &webservice);
Q_DECL_EXPORT QCFVariant cf_GetSOAPResponseHeader(const QString &_namespace, const QString &name, bool asXML = false);
Q_DECL_EXPORT QString cf_GetTempDirectory();
Q_DECL_EXPORT QString cf_GetTempFile(const QString &dir, const QString &prefix);
Q_DECL_EXPORT QString cf_GetTemplatePath();
Q_DECL_EXPORT int cf_GetTickCount();
Q_DECL_EXPORT QCFVariant cf_GetTimeZoneInfo();
Q_DECL_EXPORT QString cf_GetToken(const QString &string, int index, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_GetUserRoles();
Q_DECL_EXPORT QString cf_GetWriteableImageFormats();
Q_DECL_EXPORT QString cf_Hash(const QString &string, const QString &algorithm, const QString &encoding = "");
Q_DECL_EXPORT int cf_Hour(const QDateTime &date);
Q_DECL_EXPORT QString cf_HTMLCodeFormat(const QString &string, double version);
Q_DECL_EXPORT QString cf_HTMLEditFormat(const QString &string, double version);
Q_DECL_EXPORT bool cf_IIf(bool condition, const QString &string_expression1, const QString &string_expression2);
Q_DECL_EXPORT void cf_ImageAddBorder(QCFVariant &name, int thickness = 1, const QString &color = "", const QString &borderType = "constant");
Q_DECL_EXPORT void cf_ImageBlur(QCFVariant &name, int blurRadius = 3);
Q_DECL_EXPORT void cf_ImageClearRect(QCFVariant &name, int x, int y, int width, int height);
Q_DECL_EXPORT QCFVariant cf_ImageCopy(QCFVariant &name, int x, int y, int width, int height, int dx = 0, int dy = 0);
Q_DECL_EXPORT void cf_ImageCrop(QCFVariant &name, int x, int y, int width, int height);
Q_DECL_EXPORT void cf_ImageDrawArc(QCFVariant &name, int x, int y, int width, int height, int startAngle, double arcAngle, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawBeveledRect(QCFVariant &name, int x, int y, int width, int height, bool raised = false, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawCubicCurve(QCFVariant &name, int ctrlx1, int ctrly1, int ctrlx2, int ctrly2, int x1, int y1, int x2, int y2);
Q_DECL_EXPORT void cf_ImageDrawLine(QCFVariant &name, int x1, int y1, int x2, int y2);
Q_DECL_EXPORT void cf_ImageDrawLines(QCFVariant &name, const QCFVariant &xcoords, const QCFVariant &ycoords, bool isPolygon = false, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawOval(QCFVariant &name, int x, int y, int width, int height, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawPoint(QCFVariant &name, int x, int y);
Q_DECL_EXPORT void cf_ImageDrawQuadraticCurve(QCFVariant &name, int ctrlx1, int ctrly1, int ctrlx2, int ctrly2, int x1, int y1, int x2, int y2);
Q_DECL_EXPORT void cf_ImageDrawRect(QCFVariant &name, int x, int y, int width, int height, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawRoundRect(QCFVariant &name, int x, int y, int width, int height, int arcWidth, int arcHeight, bool filled = false);
Q_DECL_EXPORT void cf_ImageDrawText(QCFVariant &name, const QString &str, int x, int y, const QCFVariant &attributeCollection = QCFVariant());
Q_DECL_EXPORT void cf_ImageFlip(QCFVariant &name, const QString &transpose = "vertical");
Q_DECL_EXPORT QCFVariant cf_ImageGetBlob(const QCFVariant &source);
Q_DECL_EXPORT QCFVariant cf_ImageGetBufferedImage(const QCFVariant &name);
Q_DECL_EXPORT QString cf_ImageGetEXIFTag(const QCFVariant &name, const QString &tagName);
Q_DECL_EXPORT int cf_ImageGetHeight(const QCFVariant &name);
Q_DECL_EXPORT QString cf_ImageGetIPTCTag(const QCFVariant &name, const QString &tagName);
Q_DECL_EXPORT int cf_ImageGetWidth(const QCFVariant &name);
Q_DECL_EXPORT void cf_ImageGrayscale(QCFVariant &name);
Q_DECL_EXPORT QCFVariant cf_ImageInfo(const QCFVariant &name);
Q_DECL_EXPORT void cf_ImageNegative(QCFVariant &name);
Q_DECL_EXPORT QCFVariant cf_ImageNew(const QString &source, int width = 0, int height = 0, const QString &imageType = "", const QString canvasColor = "black");
Q_DECL_EXPORT void cf_ImageOverlay(QCFVariant &source1, const QCFVariant &source2);
Q_DECL_EXPORT QCFVariant cf_ImagePaste(QCFVariant &image1, const QCFVariant &image2, int x, int y);
Q_DECL_EXPORT QCFVariant cf_ImageRead(const QString &path);
Q_DECL_EXPORT QCFVariant cf_ImageReadBase64(const QString &string);
Q_DECL_EXPORT void cf_ImageResize(QCFVariant &name, int width, int height, const QString &interpolation = "highestQuality", int blurFactor = 2); // TODO: Verify blurFactor default value. It's not it the docs
Q_DECL_EXPORT void cf_ImageRotate(QCFVariant &name, double angle, int x = 2, int y = 2, const QString &interpolation = "nearest");
Q_DECL_EXPORT QCFVariant cf_ImageRotateDrawingAxis(QCFVariant &name, double angle, int x = 0, int y = 0);
Q_DECL_EXPORT void cf_ImageScaleToFit(QCFVariant &name, const QString &fitWidth, const QString &fitHeight, const QString &interpolation = "highestQuality", int blurFactor = 2); // TODO: Verify blurFactor default value. It's not it the docs
Q_DECL_EXPORT void cf_ImageSetAntialiasing(QCFVariant &name, bool antialias = true);
Q_DECL_EXPORT void cf_ImageSetBackgroundColor(QCFVariant &name, const QString &color);
Q_DECL_EXPORT void cf_ImageSetDrawingColor(QCFVariant &name, const QString &color);
Q_DECL_EXPORT void cf_ImageSetDrawingStroke(QCFVariant &name, const QCFVariant &attributeCollection = QCFVariant());
Q_DECL_EXPORT void cf_ImageSetDrawingTransparency(QCFVariant &name, double percent);
Q_DECL_EXPORT void cf_ImageSharpen(QCFVariant &name, double gain = 1.0);
Q_DECL_EXPORT void cf_ImageShear(QCFVariant &name, double shear, const QString &direction = "horizontal", const QString &interpolation = "nearest");
Q_DECL_EXPORT void cf_ImageShearDrawingAxis(QCFVariant &name, double shx, double shy);
Q_DECL_EXPORT void cf_ImageTranslate(QCFVariant &name, int xTrans, int yTrans, const QString &interpolation = "nearest");
Q_DECL_EXPORT void cf_ImageTranslateDrawingAxis(QCFVariant &name, int x, int y);
Q_DECL_EXPORT void cf_ImageWrite(const QCFVariant &name, const QString &destination = "", double quality = 0.75);
Q_DECL_EXPORT QString cf_ImageWriteBase64(const QCFVariant &name, const QString &destination, const QString &format, bool inHTMLFormat = false);
Q_DECL_EXPORT void cf_ImageXORDrawingMode(QCFVariant &name, const QString &c1);
Q_DECL_EXPORT double cf_IncrementValue(double number);
Q_DECL_EXPORT int cf_InputBaseN(const QString &string, int radix);
Q_DECL_EXPORT QString cf_Insert(const QString &substring, const QString &string, int position);
Q_DECL_EXPORT QString cf_Int(double number);
Q_DECL_EXPORT bool cf_IsArray(const QCFVariant &var, int level = 0);
Q_DECL_EXPORT bool cf_IsBinary(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsBoolean(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsCustomFunction(const QString &name);
Q_DECL_EXPORT bool cf_IsDate(const QString &string);
Q_DECL_EXPORT bool cf_IsDDX(const QString &path_or_string);
Q_DECL_EXPORT bool cf_IsDebugMode();
Q_DECL_EXPORT bool cf_IsDefined(QCFWorkerThread *thisTemplate, const QString &variable_name);
Q_DECL_EXPORT bool cf_IsImage(const QCFVariant &name);
Q_DECL_EXPORT bool cf_IsImageFile(const QCFVariant &path);
Q_DECL_EXPORT bool cf_IsInstanceOf(const QCFVariant &object, const QString &typeName);
Q_DECL_EXPORT bool cf_IsJSON(const QString &var);
Q_DECL_EXPORT bool cf_IsLeapYear(int year);
Q_DECL_EXPORT bool cf_IsLocalHost(const QString &ipaddress);
Q_DECL_EXPORT bool cf_IsNumeric(const QString &string);
Q_DECL_EXPORT bool cf_IsNumericDate(double number);
Q_DECL_EXPORT bool cf_IsObject(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsPDFFile(const QString &path);
Q_DECL_EXPORT bool cf_IsPDFObject(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsQuery(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsSimpleValue(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsSOAPRequest();
Q_DECL_EXPORT bool cf_IsStruct(const QCFVariant &variable);
Q_DECL_EXPORT bool cf_IsUserInAnyRole();
Q_DECL_EXPORT bool cf_IsUserInRole(const QString &role_name);
Q_DECL_EXPORT bool cf_IsUserLoggedIn();
Q_DECL_EXPORT bool cf_IsValid(const QString &type, const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsValid(const QString &type, const QCFVariant &value, int min, int max);
Q_DECL_EXPORT bool cf_IsValid(const QString &type, const QCFVariant &value, const QString &pattern);
Q_DECL_EXPORT bool cf_IsWDDX(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXML(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXmlAttribute(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXmlDoc(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXmlElem(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXmlNode(const QCFVariant &value);
Q_DECL_EXPORT bool cf_IsXmlRoot(const QCFVariant &value);
Q_DECL_EXPORT QCFVariant cf_JavaCast(const QString &type, const QCFVariant &value);
Q_DECL_EXPORT QString cf_JSStringFormat(const QString &string);
Q_DECL_EXPORT QString cf_LCase(const QString &string);
Q_DECL_EXPORT QString cf_Left(const QString &string, int count);
Q_DECL_EXPORT int cf_Len(const QString &string);
Q_DECL_EXPORT QString cf_ListAppend(QString &list, const QString &value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListChangeDelims(QString &list, const QString &new_delimiter, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListContains(const QString &list, const QString &substring, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListContainsNoCase(const QString &list, const QString &substring, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListDeleteAt(QString &list, int position, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListFind(const QString &list, const QString &value, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListFindNoCase(const QString &list, const QString &value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListFirst(const QString &list, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListGetAt(const QString &list, int position, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListInsertAt(QString &list, int position, const QString value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListLast(const QString &list, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListLen(const QString &list, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListPrepend(QString &list, const QString &value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListQualify(QString &list, const QString &quallifier, const QString &delimiters = ",", const QString elements = "all"); // TODO: Check if all is default. Missing from the docs.
Q_DECL_EXPORT QString cf_ListRest(const QString &list, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListSetAt(QString &list, int position, const QString value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_ListSort(QString &list, const QString sort_type, const QString sort_order = "asc", const QString &delimiters = ",");
Q_DECL_EXPORT QCFVariant cf_ListToArray(const QString &list, const QString &delimiters = ",", bool includeEmptyFields = false);
Q_DECL_EXPORT int cf_ListValueCount(const QString &list, const QString value, const QString &delimiters = ",");
Q_DECL_EXPORT int cf_ListValueCountNoCase(const QString &list, const QString value, const QString &delimiters = ",");
Q_DECL_EXPORT QString cf_LJustify(const QString &string, int length);
Q_DECL_EXPORT double cf_Log(double number);
Q_DECL_EXPORT double cf_Log10(double number);
Q_DECL_EXPORT QString cf_LSCurrencyFormat(double number, const QString &type = "local", const QString locale = "");
Q_DECL_EXPORT QString cf_LSDateFormat(const QDateTime &date, const QString &mask = "medium", const QString &locale = "");
Q_DECL_EXPORT QString cf_LSEuroCurrencyFormat(double currency_number, const QString &locale = "", const QString &type = "local");
Q_DECL_EXPORT bool cf_LSIsCurrency(const QString &string, const QString &locale = "");
Q_DECL_EXPORT bool cf_LSIsDate(const QString &string, const QString &locale = "");
Q_DECL_EXPORT bool cf_LSIsNumeric(const QString &string, const QString &locale = "");
Q_DECL_EXPORT QString cf_LSNumberFormat(double number, const QString &mask = "medium", const QString &locale = "");
Q_DECL_EXPORT QString cf_LSParseCurrency(const QString &string, const QString &locale = "");
Q_DECL_EXPORT QDateTime cf_LSParseDateTime(const QString &string, const QString &locale = "");
Q_DECL_EXPORT QString cf_LSParseEuroCurrency(const QString &currency_string, const QString &locale = "");
Q_DECL_EXPORT QString cf_LSParseNumber(const QString &string, const QString &locale = "");
Q_DECL_EXPORT QString cf_LSTimeFormat(const QDateTime &time, const QString &locale = "short");
Q_DECL_EXPORT QString cf_LSTimeFormat(const QString &time, const QString &locale = "short");
Q_DECL_EXPORT QString cf_LTrim(const QString &string);
Q_DECL_EXPORT double cf_Max(double number1, double number2);
Q_DECL_EXPORT QString cf_Mid(const QString &string, int start, int count);
Q_DECL_EXPORT double cf_Min(double number1, double number2);
Q_DECL_EXPORT int cf_Minute(const QDateTime &date);
Q_DECL_EXPORT int cf_Month(const QDateTime &date);
Q_DECL_EXPORT QString cf_MonthAsString(const QDateTime &date, const QString &locale = "");
Q_DECL_EXPORT QDateTime cf_Now();
Q_DECL_EXPORT QString cf_NumberFormat(double number, const QString &mask = "");
Q_DECL_EXPORT QString cf_ParagraphFormat(const QString &string);
Q_DECL_EXPORT QDateTime cf_ParseDateTime(const QString &datetime_string, const QString &pop_conversion = "standard");
Q_DECL_EXPORT double cf_Pi();
Q_DECL_EXPORT QCFVariant cf_PrecisionEvaluate(const QStringList &string_expressions);
Q_DECL_EXPORT QString cf_PreserveSingleQuotes(const QString &variable);
Q_DECL_EXPORT int cf_Quarter(const QDateTime &date);
Q_DECL_EXPORT int cf_QueryAddColumn(QCFVariant &query, const QString &column_name, const QString &datatype = "", const QString &array_name = "");
Q_DECL_EXPORT int cf_QueryAddRow(QCFVariant &query, int number = 1);
Q_DECL_EXPORT QCFVariant cf_QueryConvertForGrid(const QCFVariant &query, int page, int pageSize);
Q_DECL_EXPORT QCFVariant cf_QueryNew(const QString &columnlist, const QString &columntypelist = "");
Q_DECL_EXPORT bool cf_QuerySetCell(QCFVariant &query, const QString &column_name, const QCFVariant &value, int row_number = -1);
Q_DECL_EXPORT QString cf_QuotedValueList(const QCFVariant &query_column, const QString &delimiter = ",");
Q_DECL_EXPORT double cf_Rand(const QString &algorithm = "CFMX_COMPAT");
Q_DECL_EXPORT double cf_Randomize(int number, const QString &algorithm = "CFMX_COMPAT");
Q_DECL_EXPORT int cf_RandRange(int number1, int number2, const QString &algorithm = "CFMX_COMPAT");
Q_DECL_EXPORT QCFVariant cf_REFind(const QString &reg_expression, const QString &string, int start = 1, bool returnsubexpressions = false);
Q_DECL_EXPORT QCFVariant cf_REFindNoCase(const QString &reg_expression, const QString &string, int start = 1, bool returnsubexpressions = false);
Q_DECL_EXPORT void cf_ReleaseComObject(QCFVariant &objectName);
Q_DECL_EXPORT QCFVariant cf_REMatch(const QString &reg_expression, const QString &string);
Q_DECL_EXPORT QCFVariant cf_REMatchNoCase(const QString &reg_expression, const QString &string);
Q_DECL_EXPORT QString cf_RemoveChars(const QString &string, int start, int count);
Q_DECL_EXPORT QString cf_RepeatString(const QString &string, int count);
Q_DECL_EXPORT QString cf_Replace(const QString &string, const QString &substring1, const QString &substring2, const QString &scope = "one");
Q_DECL_EXPORT QString cf_ReplaceList(QString &list, const QString &list1, const QString &list2);
Q_DECL_EXPORT QString cf_ReplaceNoCase(const QString &string, const QString &substring1, const QString &substring2, const QString &scope = "one");
Q_DECL_EXPORT QString cf_REReplace(const QString &string, const QString &reg_expression, const QString &substring, const QString &scope = "one");
Q_DECL_EXPORT QString cf_REReplaceNoCase(const QString &string, const QString &reg_expression, const QString &substring, const QString &scope = "one");
Q_DECL_EXPORT QString cf_Reverse(const QString &string);
Q_DECL_EXPORT QString cf_Right(const QString &string, int count);
Q_DECL_EXPORT QString cf_RJustify(const QString &string, int length);
Q_DECL_EXPORT int cf_Round(double number);
Q_DECL_EXPORT QString cf_RTrim(const QString &string);
Q_DECL_EXPORT int cf_Second(const QDateTime &date);
Q_DECL_EXPORT QString cf_SendGatewayMessage(const QString &gatewayID, const QCFVariant &data);
Q_DECL_EXPORT QString cf_SerializeJSON(const QCFVariant &var, bool serializeQueryByColumns = false);
Q_DECL_EXPORT void cf_SetEncoding(const QString &scope_name, const QString &charset);
Q_DECL_EXPORT QString cf_SetLocale(const QString &new_locale);
Q_DECL_EXPORT QString cf_SetProfileString(const QString &iniPath, const QString &section, const QString &entry, const QString &value);
Q_DECL_EXPORT QCFVariant cf_SetVariable(const QString &name, const QCFVariant &value);
Q_DECL_EXPORT int cf_Sgn(double number);
Q_DECL_EXPORT double cf_Sin(double number);
Q_DECL_EXPORT void cf_Sleep(int duration);
Q_DECL_EXPORT QString cf_SpanExcluding(const QString &string, const QCFVariant &set);
Q_DECL_EXPORT QString cf_SpanIncluding(const QString &string, const QCFVariant &set);
Q_DECL_EXPORT double cf_Sqr(double number);
Q_DECL_EXPORT QString cf_StripCR(const QString &string);
Q_DECL_EXPORT bool cf_StructAppend(QCFVariant &struct1, const QCFVariant &struct2, bool overwriteFlag = true);
Q_DECL_EXPORT bool cf_StructClear(QCFVariant &structure);
Q_DECL_EXPORT QCFVariant cf_StructCopy(QCFVariant &structure);
Q_DECL_EXPORT int cf_StructCount(const QCFVariant &structure);
Q_DECL_EXPORT bool cf_StructDelete(QCFVariant &structure, const QString &key, bool indicatenotexisting = false);
Q_DECL_EXPORT QCFVariant cf_StructFind(const QCFVariant &structure, const QString &key);
Q_DECL_EXPORT QCFVariant cf_StructFindKey(const QCFVariant &top, const QString &value, const QString &scope = "one");
Q_DECL_EXPORT QCFVariant cf_StructFindValue(const QCFVariant &top, const QString &value, const QString &scope = "one");
Q_DECL_EXPORT QCFVariant cf_StructGet(const QString &pathDesired);
Q_DECL_EXPORT bool cf_StructInsert(QCFVariant &structure, const QString &key, const QCFVariant &value, bool allowoverwrite = false);
Q_DECL_EXPORT bool cf_StructIsEmpty(const QCFVariant &structure);
Q_DECL_EXPORT QCFVariant cf_StructKeyArray(const QCFVariant &structure);
Q_DECL_EXPORT bool cf_StructKeyExists(const QCFVariant &structure, const QString &key);
Q_DECL_EXPORT QString cf_StructKeyList(const QCFVariant &structure, const QString &delimiter = ",");
Q_DECL_EXPORT QCFVariant cf_StructNew();
Q_DECL_EXPORT QCFVariant cf_StructSort(const QCFVariant &base, const QString &sortType = "text", const QString &sortOrder = "asc", const QString &pathToSubElement = "");
Q_DECL_EXPORT bool cf_StructUpdate(QCFVariant &structure, const QString &key, const QCFVariant &value);
Q_DECL_EXPORT double cf_Tan(double number);
Q_DECL_EXPORT QString cf_TimeFormat(const QDateTime &time, const QString &mask = "medium");
Q_DECL_EXPORT QString cf_ToBase64(const QString &object, const QString &encoding = "");
Q_DECL_EXPORT QString cf_ToBase64(const QByteArray &object, const QString &encoding = "");
Q_DECL_EXPORT QCFVariant cf_ToBinary(const QString &string);
Q_DECL_EXPORT QCFVariant cf_ToBinary(const QByteArray &string);
Q_DECL_EXPORT QString cf_ToScript(const QString &cfvar, const QString &javascriptvar, bool outputformat = true, bool ASFormat = false);
Q_DECL_EXPORT QString cf_ToString(const QCFVariant &value, const QString &encoding = "");
Q_DECL_EXPORT QString cf_Trim(const QString &string);
Q_DECL_EXPORT QString cf_UCase(const QString &string);
Q_DECL_EXPORT QString cf_URLDecode(QString &urlEncodedString, const QString &charset = "");
Q_DECL_EXPORT QString cf_URLEncodedFormat(const QString &string, const QString &charset = "");
Q_DECL_EXPORT QString cf_URLSessionFormat(const QString &request_URL);
Q_DECL_EXPORT double cf_Val(const QString &string);
Q_DECL_EXPORT QString cf_ValueList(const QCFVariant &query_column, const QString delimiter = ",");
Q_DECL_EXPORT void cf_VerifyClient();
Q_DECL_EXPORT int cf_Week(const QDateTime &date);
Q_DECL_EXPORT QString cf_Wrap(const QString &string, int limit, bool strip = false);
Q_DECL_EXPORT void cf_WriteOutput(QCFWorkerThread *thisTemplate, const QString &string);
Q_DECL_EXPORT bool cf_XmlChildPos(const QCFVariant &elem, const QCFVariant &childName, int N);
Q_DECL_EXPORT QCFVariant cf_XmlElemNew(QCFVariant &xmlObj, const QString &childName);
Q_DECL_EXPORT QCFVariant cf_XmlElemNew(QCFVariant &xmlObj, const QString &_namespace, const QString &childName);
Q_DECL_EXPORT QString cf_XmlFormat(const QString &string);
Q_DECL_EXPORT QString cf_XmlGetNodeType(const QCFVariant &xmlNode);
Q_DECL_EXPORT QCFVariant cf_XmlNew(bool caseSensitive = false);
Q_DECL_EXPORT QCFVariant cf_XmlParse(const QString &xmlText, bool caseSensitive = false, const QString &validator = "");
Q_DECL_EXPORT QCFVariant cf_XmlSearch(const QCFVariant &xmlDoc, const QString &xPathString);
Q_DECL_EXPORT QString cf_XmlTransform(QCFVariant &xml, const QString &xsl, const QCFVariant &parameters = QCFVariant());
Q_DECL_EXPORT QCFVariant cf_XmlValidate(const QCFVariant &xmlDoc, const QString &validator = "");
Q_DECL_EXPORT int cf_Year(const QDateTime &date);
Q_DECL_EXPORT bool cf_YesNoFormat(const QCFVariant &value);
