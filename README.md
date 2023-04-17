# Customized_Cpp_array

we create a powerful Array class that performs range checking to ensure
that subscripts remain within the bounds of the Array. The class allows one Array object to
be assigned to another with the assignment operator. Array objects know their size, so the
size does not need to be passed separately to functions that receive Array parameters. Entire
Arrays can be input or output with the stream extraction and stream insertion operators,
respectively. You can compare Arrays with the equality operators == and !=. 

Pointer-based arrays have many problems, including:
• A program can easily “walk off” either end of a built-in array, because C++ does
not check whether subscripts fall outside the range of the array (though you can still
do this explicitly). 
• Built-in arrays of size n must number their elements 0, …, n – 1; alternate subscript ranges are not allowed.
• An entire built-in array cannot be input or output at once; each element must be
read or written individually (unless the array is a null-terminated C string). 
• Two built-in arrays cannot be meaningfully compared with equality or relational
operators (because the array names are simply pointers to where the arrays begin
in memory and two arrays will always be at different memory locations). 
• When a built-in array is passed to a general-purpose function designed to handle
arrays of any size, the array’s size must be passed as an additional argument. 
• One built-in array cannot be assigned to another with the assignment operator(s).
