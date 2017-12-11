function varargout = irisdetection(varargin)
% IRISDETECTION MATLAB code for irisdetection.fig
%      IRISDETECTION, by itself, creates a new IRISDETECTION or raises the existing
%      singleton*.
%
%      H = IRISDETECTION returns the handle to a new IRISDETECTION or the handle to
%      the existing singleton*.
%
%      IRISDETECTION('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in IRISDETECTION.M with the given input arguments.
%
%      IRISDETECTION('Property','Value',...) creates a new IRISDETECTION or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before irisdetection_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to irisdetection_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help irisdetection

% Last Modified by GUIDE v2.5 17-Mar-2015 14:28:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @irisdetection_OpeningFcn, ...
                   'gui_OutputFcn',  @irisdetection_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before irisdetection is made visible.
function irisdetection_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to irisdetection (see VARARGIN)

% Choose default command line output for irisdetection
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes irisdetection wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = irisdetection_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[filename pathname, temp] = uigetfile('*.jpg;*.bmp;*.png', 'Choose Image');
cd(pathname);
I = imread(filename);
handles.filename = I;
guidata(hObject,handles);


 axes(handles.axes1);
 imshow(I);


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
[filename1 pathname, temp] = uigetfile('*.jpg;*.bmp;*.png', 'Choose Image');
cd(pathname);
I = imread(filename1);
handles.filename1 = I;
guidata(hObject,handles);


 axes(handles.axes3);
 imshow(I);


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
im = handles.filename;
im1 = handles.filename1;
score = inputimage(im,im1);
if(score<0.30)
set(handles.edit1,'string','Accepted');
else
    set(handles.edit1,'string','Rejected');
end