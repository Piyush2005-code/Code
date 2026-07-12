basename = filename.split(b'/')[-1]
has_extension = b'.' in basename

if not has_extension:
    contents = value.get_contents_by_identifier(blob_id)
    if value.is_binary(contents):
        return (None, mode, blob_id)
        
return (filename, mode, blob_id)
